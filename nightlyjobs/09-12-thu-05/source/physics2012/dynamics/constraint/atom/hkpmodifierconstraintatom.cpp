// File Line: 19
// RVA: 0xD98930
void __fastcall hkpMassChangerModifierConstraintAtom::collisionResponseBeginCallback(hkpMassChangerModifierConstraintAtom *this, hkContactPoint *cp, hkpSimpleConstraintInfoInitInput *inA, hkpBodyVelocity *velA, hkpSimpleConstraintInfoInitInput *inB)
{
  hkVector4f v5; // xmm8
  hkpMassChangerModifierConstraintAtom *v6; // rbp
  signed __int64 v7; // rsi
  hkTransformf *v8; // rbx
  hkMatrix3f *v9; // rdi
  hkVector4f v10; // xmm5
  __m128 v11; // xmm4
  hkSimdFloat32 scale; // [rsp+20h] [rbp-A8h]
  hkMatrix3f v13; // [rsp+30h] [rbp-98h]
  hkMatrix3f aTb; // [rsp+60h] [rbp-68h]

  v5.m_quad = (__m128)this->m_factorA;
  v6 = this;
  v7 = 2i64;
  do
  {
    inA->m_invMasses.m_quad = _mm_mul_ps(inA->m_invMasses.m_quad, v5.m_quad);
    if ( _mm_movemask_ps(
           _mm_and_ps(
             _mm_cmpeqps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 225), v5.m_quad),
             _mm_cmpeqps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 78), v5.m_quad))) & 1 )
    {
      scale.m_real = _mm_shuffle_ps(v5.m_quad, v5.m_quad, 0);
      hkMatrix3f::mul(&inA->m_invInertia, &scale);
    }
    else
    {
      v8 = inA->m_transform;
      v9 = &inA->m_invInertia;
      hkMatrix3f::setMulInverseMul(&aTb, &inA->m_transform->m_rotation, &inA->m_invInertia);
      hkMatrix3f::setMul(&v13, &aTb, (hkMatrix3f *)&v8->m_rotation.m_col0);
      v10.m_quad = (__m128)v13.m_col0;
      v11 = _mm_mul_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  (__m128)xmmword_141A9C680,
                  _mm_or_ps(
                    _mm_andnot_ps((__m128)xmmword_141A9C660, v13.m_col0.m_quad),
                    _mm_and_ps(v13.m_col1.m_quad, (__m128)xmmword_141A9C660))),
                _mm_and_ps(v13.m_col2.m_quad, (__m128)xmmword_141A9C680)),
              v5.m_quad);
      v10.m_quad.m128_f32[0] = v11.m128_f32[0];
      v13.m_col0 = (hkVector4f)v10.m_quad;
      v13.m_col2.m_quad = _mm_or_ps(
                            _mm_and_ps((__m128)xmmword_141A9C680, v11),
                            _mm_andnot_ps((__m128)xmmword_141A9C680, v13.m_col2.m_quad));
      v13.m_col1.m_quad = _mm_or_ps(
                            _mm_and_ps(v11, (__m128)xmmword_141A9C660),
                            _mm_andnot_ps((__m128)xmmword_141A9C660, v13.m_col1.m_quad));
      hkMatrix3f::setMulInverse(&aTb, &v13, &v8->m_rotation);
      hkMatrix3f::setMul(v9, (hkMatrix3f *)&v8->m_rotation.m_col0, &aTb);
    }
    v5.m_quad = (__m128)v6->m_factorB;
    inA = inB;
    --v7;
  }
  while ( v7 );
}

// File Line: 60
// RVA: 0xD98AD0
void __fastcall hkpMassChangerModifierConstraintAtom::collisionResponseEndCallback(hkpMassChangerModifierConstraintAtom *this, hkContactPoint *cp, float impulseApplied, hkpSimpleConstraintInfoInitInput *inA)
{
  ;
}

// File Line: 64
// RVA: 0xD98AE0
void __fastcall hkpCenterOfMassChangerModifierConstraintAtom::collisionResponseBeginCallback(hkpCenterOfMassChangerModifierConstraintAtom *this, hkContactPoint *cp, hkpSimpleConstraintInfoInitInput *inA, hkpBodyVelocity *velA, hkpSimpleConstraintInfoInitInput *inB, hkpBodyVelocity *velB)
{
  hkVector4f v6; // xmm1
  __m128 v7; // xmm4
  hkVector4f v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm1

  v6.m_quad = (__m128)this->m_displacementA;
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 85), inA->m_transform->m_rotation.m_col1.m_quad),
           _mm_mul_ps(
             _mm_shuffle_ps(this->m_displacementA.m_quad, v6.m_quad, 0),
             inA->m_transform->m_rotation.m_col0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 170), inA->m_transform->m_rotation.m_col2.m_quad));
  v8.m_quad = (__m128)this->m_displacementB;
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 85), inB->m_transform->m_rotation.m_col1.m_quad),
           _mm_mul_ps(
             _mm_shuffle_ps(this->m_displacementB.m_quad, v8.m_quad, 0),
             inB->m_transform->m_rotation.m_col0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 170), inB->m_transform->m_rotation.m_col2.m_quad));
  inA->m_massRelPos.m_quad = _mm_sub_ps(inA->m_massRelPos.m_quad, v7);
  inB->m_massRelPos.m_quad = _mm_sub_ps(inB->m_massRelPos.m_quad, v9);
  v10 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(velA->m_angular.m_quad, velA->m_angular.m_quad, 201), v7),
          _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), velA->m_angular.m_quad));
  v11 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(velB->m_angular.m_quad, velB->m_angular.m_quad, 201), v9),
          _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), velB->m_angular.m_quad));
  velA->m_linear.m_quad = _mm_sub_ps(velA->m_linear.m_quad, _mm_shuffle_ps(v10, v10, 201));
  velB->m_linear.m_quad = _mm_sub_ps(velB->m_linear.m_quad, _mm_shuffle_ps(v11, v11, 201));
}

// File Line: 78
// RVA: 0xD98BB0
void __fastcall hkpCenterOfMassChangerModifierConstraintAtom::collisionResponseEndCallback(hkpCenterOfMassChangerModifierConstraintAtom *this, hkContactPoint *cp, float impulseApplied, hkpSimpleConstraintInfoInitInput *inA, hkpBodyVelocity *velA, hkpSimpleConstraintInfoInitInput *inB, hkpBodyVelocity *velB)
{
  hkVector4f v7; // xmm1
  __m128 v8; // xmm4
  hkVector4f v9; // xmm1
  hkVector4f v10; // xmm0
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  __m128 v13; // xmm4
  hkVector4f v14; // xmm0
  __m128 v15; // xmm2
  __m128 v16; // xmm1

  v7.m_quad = (__m128)this->m_displacementA;
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 85), inA->m_transform->m_rotation.m_col1.m_quad),
           _mm_mul_ps(
             _mm_shuffle_ps(this->m_displacementA.m_quad, v7.m_quad, 0),
             inA->m_transform->m_rotation.m_col0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 170), inA->m_transform->m_rotation.m_col2.m_quad));
  v9.m_quad = (__m128)this->m_displacementB;
  v10.m_quad = (__m128)velA->m_angular;
  v11 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 85), inB->m_transform->m_rotation.m_col1.m_quad),
            _mm_mul_ps(
              _mm_shuffle_ps(this->m_displacementB.m_quad, v9.m_quad, 0),
              inB->m_transform->m_rotation.m_col0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 170), inB->m_transform->m_rotation.m_col2.m_quad));
  v12 = _mm_mul_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 201), v8);
  v13 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v10.m_quad);
  v14.m_quad = (__m128)velB->m_angular;
  v15 = _mm_sub_ps(v12, v13);
  velA->m_linear.m_quad = _mm_add_ps(_mm_shuffle_ps(v15, v15, 201), velA->m_linear.m_quad);
  v16 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v14.m_quad, v14.m_quad, 201), v11),
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v14.m_quad));
  velB->m_linear.m_quad = _mm_add_ps(_mm_shuffle_ps(v16, v16, 201), velB->m_linear.m_quad);
}

// File Line: 91
// RVA: 0xD98C70
void __fastcall hkpSoftContactModifierConstraintAtom::collisionResponseBeginCallback(hkpSoftContactModifierConstraintAtom *this, hkContactPoint *cp, hkpSimpleConstraintInfoInitInput *inA, hkpBodyVelocity *velA, hkpSimpleConstraintInfoInitInput *inB, hkpBodyVelocity *velB)
{
  s_bodyVelocities[0].m_linear = velA->m_linear;
  xmmword_1424AF270 = (__int128)velA->m_angular;
  xmmword_1424AF280 = (__int128)velB->m_linear;
  xmmword_1424AF290 = (__int128)velB->m_angular;
}

// File Line: 99
// RVA: 0xD98CB0
void __fastcall hkpSoftContactModifierConstraintAtom::collisionResponseEndCallback(hkpSoftContactModifierConstraintAtom *this, hkContactPoint *cp, float impulseApplied, hkpSimpleConstraintInfoInitInput *inA, hkpBodyVelocity *velA, hkpSimpleConstraintInfoInitInput *inB, hkpBodyVelocity *velB)
{
  __m128 v7; // xmm3
  hkVector4f v8; // xmm2
  hkVector4f v9; // xmm2

  v7 = _mm_shuffle_ps((__m128)LODWORD(this->m_tau), (__m128)LODWORD(this->m_tau), 0);
  v8.m_quad = (__m128)velA->m_angular;
  velA->m_linear.m_quad = _mm_add_ps(
                            _mm_mul_ps(_mm_sub_ps(velA->m_linear.m_quad, s_bodyVelocities[0].m_linear.m_quad), v7),
                            s_bodyVelocities[0].m_linear.m_quad);
  velA->m_angular.m_quad = _mm_add_ps(
                             _mm_mul_ps(_mm_sub_ps(v8.m_quad, (__m128)xmmword_1424AF270), v7),
                             (__m128)xmmword_1424AF270);
  v9.m_quad = (__m128)velB->m_angular;
  velB->m_linear.m_quad = _mm_add_ps(
                            _mm_mul_ps(_mm_sub_ps(velB->m_linear.m_quad, (__m128)xmmword_1424AF280), v7),
                            (__m128)xmmword_1424AF280);
  velB->m_angular.m_quad = _mm_add_ps(
                             _mm_mul_ps(_mm_sub_ps(v9.m_quad, (__m128)xmmword_1424AF290), v7),
                             (__m128)xmmword_1424AF290);
}

// File Line: 112
// RVA: 0xD98D30
void __fastcall hkpMovingSurfaceModifierConstraintAtom::collisionResponseBeginCallback(hkpMovingSurfaceModifierConstraintAtom *this, hkContactPoint *cp, hkpSimpleConstraintInfoInitInput *inA, hkpBodyVelocity *velA, hkpSimpleConstraintInfoInitInput *inB, hkpBodyVelocity *velB)
{
  hkVector4f v6; // xmm3
  __m128 v7; // xmm1

  v6.m_quad = (__m128)this->m_velocity;
  v7 = _mm_mul_ps(cp->m_separatingNormal.m_quad, v6.m_quad);
  velB->m_linear.m_quad = _mm_add_ps(
                            _mm_sub_ps(
                              v6.m_quad,
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)),
                                  _mm_shuffle_ps(v7, v7, 170)),
                                v6.m_quad)),
                            velB->m_linear.m_quad);
}

// File Line: 122
// RVA: 0xD98D70
void __fastcall hkpMovingSurfaceModifierConstraintAtom::collisionResponseEndCallback(hkpMovingSurfaceModifierConstraintAtom *this, hkContactPoint *cp, float impulseApplied, hkpSimpleConstraintInfoInitInput *inA, hkpBodyVelocity *velA, hkpSimpleConstraintInfoInitInput *inB, hkpBodyVelocity *velB)
{
  hkVector4f v7; // xmm3
  __m128 v8; // xmm1

  v7.m_quad = (__m128)this->m_velocity;
  v8 = _mm_mul_ps(cp->m_separatingNormal.m_quad, v7.m_quad);
  velB->m_linear.m_quad = _mm_sub_ps(
                            velB->m_linear.m_quad,
                            _mm_sub_ps(
                              v7.m_quad,
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                                  _mm_shuffle_ps(v8, v8, 170)),
                                v7.m_quad)));
}

// File Line: 133
// RVA: 0xD98DB0
__int64 __fastcall hkpIgnoreModifierConstraintAtom::getConstraintInfo(hkpIgnoreModifierConstraintAtom *this, hkpConstraintInfo *info)
{
  hkpConstraintInfo *v2; // rbx
  int i; // edx
  hkpConstraintData::ConstraintInfo infoOut; // [rsp+20h] [rbp-28h]

  v2 = info;
  for ( i = 0; this->m_type.m_storage >= 0x1Eu; this = (hkpIgnoreModifierConstraintAtom *)this->m_child )
    i = this->m_childSize;
  if ( this->m_type.m_storage != 29 && this->m_type.m_storage != 1 )
  {
    infoOut.m_extraSchemaSize = 0;
    hkpConstraintData::getConstraintInfoUtil((hkpConstraintAtom *)&this->m_type, i, &infoOut);
    v2->m_numSolverElemTemps -= infoOut.m_numSolverElemTemps;
    v2->m_numSolverResults -= infoOut.m_numSolverResults;
    v2->m_sizeOfSchemas -= infoOut.m_sizeOfSchemas;
  }
  return 0i64;
}

// File Line: 167
// RVA: 0xD98810
int __fastcall hkpModifierConstraintAtom::addModifierDataToConstraintInfo(hkpModifierConstraintAtom *this, hkpConstraintInfo *cinfo, char *usedFlagsOut)
{
  int result; // eax

  switch ( this->m_type.m_storage )
  {
    case 0x1Eu:
      *usedFlagsOut |= 8u;
      result = 0;
      break;
    case 0x1Fu:
      cinfo->m_sizeOfSchemas += 96;
      *usedFlagsOut |= 1u;
      result = 0;
      break;
    case 0x20u:
      *usedFlagsOut |= 0x10u;
      result = 0;
      break;
    case 0x21u:
      cinfo->m_sizeOfSchemas += 96;
      *usedFlagsOut |= 4u;
      result = 0;
      break;
    case 0x22u:
      result = hkpIgnoreModifierConstraintAtom::getConstraintInfo((hkpIgnoreModifierConstraintAtom *)this, cinfo);
      break;
    case 0x23u:
      cinfo->m_sizeOfSchemas += 224;
      *usedFlagsOut |= 2u;
      goto LABEL_8;
    default:
LABEL_8:
      result = 0;
      break;
  }
  return result;
}

// File Line: 226
// RVA: 0xD988C0
__int64 __fastcall hkpModifierConstraintAtom::addAllModifierDataToConstraintInfo(hkpModifierConstraintAtom *modifier, hkpConstraintInfo *cinfo, char *usedFlagsOut)
{
  unsigned int v3; // edi
  char *v4; // rsi
  hkpConstraintInfo *v5; // rbp
  hkpModifierConstraintAtom *i; // rbx
  int v7; // eax

  v3 = 0;
  v4 = usedFlagsOut;
  v5 = cinfo;
  for ( i = modifier; i->m_type.m_storage >= 0x1Eu; v3 |= v7 )
  {
    v7 = hkpModifierConstraintAtom::addModifierDataToConstraintInfo(i, v5, v4);
    i = (hkpModifierConstraintAtom *)i->m_child;
  }
  return v3;
}

