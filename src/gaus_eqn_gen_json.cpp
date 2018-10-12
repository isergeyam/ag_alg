#include "myjson.h"
#include "mymatr.h"

int main() {
  myVector empty(0);
  size_t k = 0, n = 0, dep_mask = 0, hash_rad = 3, hash_max = 20, itype = 0, sys_type;
  rand_t d1 = -3, d2 = 3;
  char cdep_mask[32];

  //  cin >> k >> n >> cdep_mask >> d1 >> d2 >> hash_rad >> hash_max >> itype ;

  if (!k)
    k = rand() % 3 + 4;
  if (!n)
    n = 11 - k;

  if (!dep_mask) {
    int mm = min(k, n - 1);
    int dd2 = (1 << n) - 1;
    int dd1 = (1 << (n - 1)) | (1 << (n - 3));

    if (!itype)
      itype = rand() % 3 + 1;
    if (itype == 3)
      itype = (rand() % 2) ? itype : 2;

    if (itype == 3) { // no answers
      sys_type = 0 ;
      do {
        dep_mask = myrand(dd1, dd2);
      } while (wt(dep_mask, n) < mm - 2 || wt(dep_mask, n) > mm ||
               !(dep_mask % 2));
    } else if (itype == 1) { // one answer
      sys_type = 1 ;
      dep_mask = ((1 << mm) - 1) << (n - mm);
    } else if (itype == 2) { // infinite answers
      do {
        sys_type = 2 ;
        dep_mask = myrand(dd1, dd2);
      } while (wt(dep_mask, n) < mm - 2 || wt(dep_mask, n) >= mm ||
               dep_mask % 2);
    }
  }
  Json::Value val;
  myMatrix A(k, n);
  val["problem"]["rows"]["data"] = k ;
  val["problem"]["rows"]["type"] = "int" ;
  val["problem"]["cols"]["data"] = n ;
  val["problem"]["cols"]["type"] = "int" ;
  val["answer"]["sysType"]["data"] = sys_type ;
  val["answer"]["sysType"]["type"] = "int" ;
  A.gen_step(dep_mask, d1, d2);
  myMatrix B = A.hash(hash_rad, hash_max);
  //  cout << "Исследовать систему методом Гаусса:\n" ;
  // tex_equation(B) ;
  json_matrix(B, val["problem"]["A"]);
  val["problem"]["A"]["type"] = "linear_system";
  B.gaus1();

  myMatrix B_short = B;                   // added
  B_short.del_col(B_short[0].size() - 1); // added
  B_short.gaus1();                        // added

  // cout << "\n%" << k << ' ' << n;
  // comment_matrix (B,"step") ;
  // json_matrix(B, val["hidden"]["A"]) ;
  // Json::Value &hida=val["hidden"]["A"] ;
  // hida["type"]="reference" ;
  // hida["data"][0]="problem" ;
  // hida["data"][1]="A" ;
  // cout << "%cols=\n%" ;

  // cerr << "Ответ:\n\n" ;

  size_t rk_sys = B_short.main_vect.size(); // added

  // cerr << "ранг ситстемы: " << rk_sys << "\n\n" ; //changed
  val["answer"]["rk"]["data"] = (int)rk_sys;
  val["answer"]["rk"]["type"] = "int";
  // cerr << "Главные неизвестные:\n" ;
  Json::Value &solb = val["answer"]["main"];
  // Json::Value &hidb=val["hidden"]["B"] ;
  // hidb["type"]="reference" ;
  // hidb["data"][0]="answer" ;
  // hidb["data"][1]="B" ;
  solb["type"] = "index_vector";
  solb["data"] = Json::Value(Json::arrayValue);
  for (int i = 0; i < rk_sys; i++) {
    // if (i) cerr << ", " ;
    // cerr << "$x_" << B_short.main_vect[i]+1 << "$" ;
    solb["data"].append((int)B_short.main_vect[i] + 1);
    // cout << B_short.main_vect[i]+1 << ' ' ;
  }
  // cout << "\n%rk=\n%"  << rk_sys ;
  // cerr << "\n\nСтупенчатый вид:\n$$\n" ;
  json_matrix(B, val["answer"]["step"]);
  // cerr << "$$\n" ;
  // comment_matrix (A, "easy", cerr) ;
  json_matrix(A, val["hidden"]["easy"]);
  /*
  val["answer"]["type"]["type"] = "integer";
  val["answer"]["type"]["data"] =
      (rk_sys != k) ? "совместная неопределенная" : "совместная определенная";
  */
  cout << val.toStyledString();
  
  return 0;
}
