            /************************************************\
            *                                                *
            *  RUSIAN-ARMENIAN (SLAVONIC) STATE UNIVERSITY   *
            *  Author: A. Grigoryants                        *
            *                                                *
            *      ELECTRONIC EXAMINATION SYSTEM             *
            *                                                *
            *       +++++ +   +    + + ++   ++               *
            *       +      + +    +  + + + + +               *
            *       ++      +    +++++ +  +  +               *
            *       +      + +   +   + +     +               *
            *       +++++ +   + +    + +     +               *
            *                                                *
            *                                                *
            *                                                *
            *  Copyright (C) 2003 - 2009                     *
            \************************************************/


#ifndef MYJSON_H
#define MYJSON_H

#include "mymatr.h"
#include "mypoly.h"
#include <jsoncpp/json/json.h>

string streamer(Json::Value&);
void json_matrix(myMatrix&, Json::Value&) ;

/*void comment_matrix (myMatrix&, const char*, ostream& out=cout) ;
void tex_equation (myMatrix) ;
void tex_polynom(myPolynom Y, int mod=0, ostream& out=cout, char var='x') ;
void tex_comb(myPolynom Y, int mod=0, ostream& out=cout, char var='e') ;
void tex_vect(const myVector&, ostream& out=cout) ;
void tex_plane_eqn (const myVector& , ostream& out=cout) ;
void tex_kv_frm (const myMatrix&, ostream& out=cout) ;
void tex_surf (const myMatrix&, const myVector&, const myScalar, ostream& out = cout) ;
*/
#endif
