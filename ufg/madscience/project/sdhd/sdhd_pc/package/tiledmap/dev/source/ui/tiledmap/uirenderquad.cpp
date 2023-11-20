// File Line: 31
// RVA: 0x145E610
__int64 UFG::_dynamic_initializer_for__gUIrasterState_Set_Mask0_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UIrasterState_Mask_Clear_SetBit0", 0xFFFFFFFF);
  UFG::gUIrasterState_Set_Mask0_UID = result;
  return result;
}

// File Line: 32
// RVA: 0x145E630
__int64 UFG::_dynamic_initializer_for__gUIrasterState_Set_Mask1_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UIrasterState_Mask_Clear_SetBit1", 0xFFFFFFFF);
  UFG::gUIrasterState_Set_Mask1_UID = result;
  return result;
}

// File Line: 37
// RVA: 0x145E670
__int64 UFG::_dynamic_initializer_for__gUIrasterState_Test_Mask_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UIrasterState_Mask_End", 0xFFFFFFFF);
  UFG::gUIrasterState_Test_Mask_UID = result;
  return result;
}

// File Line: 38
// RVA: 0x145E650
__int64 UFG::_dynamic_initializer_for__gUIrasterState_Test2_Mask_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UIrasterState_Mask_End2", 0xFFFFFFFF);
  UFG::gUIrasterState_Test2_Mask_UID = result;
  return result;
}

// File Line: 40
// RVA: 0x145E6B0
__int64 UFG::_dynamic_initializer_for__gUIshader_Simple_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("SIMPLE", 0xFFFFFFFF);
  UFG::gUIshader_Simple_UID = result;
  return result;
}

// File Line: 41
// RVA: 0x145E690
__int64 UFG::_dynamic_initializer_for__gUIshader_Punch_Simple_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("SIMPLEPUNCH", 0xFFFFFFFF);
  UFG::gUIshader_Punch_Simple_UID = result;
  return result;
}

// File Line: 59
// RVA: 0xBFF80
void __fastcall UFG::DrawColoredRect_Xform(Render::View *view, float x, float y, float w, float h, UFG::qColour *Color, unsigned int TextureUID, const float *UVs, const unsigned int AlphaStateUID, unsigned int RasterStateUID, UFG::qMatrix44 *TransformMatrix)
{
  Render::View *v11; // rbx
  unsigned int v12; // er8
  Illusion::Material *v13; // r8
  Render::vDynamic *v14; // rcx
  float v15; // xmm2_4
  float v16; // xmm6_4
  Render::vDynamic *v17; // rax
  float v18; // xmm2_4
  float v19; // xmm6_4
  Render::vDynamic *v20; // rax
  float v21; // xmm2_4
  float v22; // xmm6_4
  Render::vDynamic *v23; // rax
  float v24; // xmm2_4
  float v25; // xmm6_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  Render::Poly poly; // [rsp+30h] [rbp-38h]
  __int64 v29; // [rsp+38h] [rbp-30h]

  v29 = -2i64;
  v11 = view;
  v12 = _S6_1;
  if ( !(_S6_1 & 1) )
  {
    v12 = _S6_1 | 1;
    _S6_1 |= 1u;
    scale_x = 1.0 / (float)(signed int)UFG::UIScreenManager::s_instance->m_flashWidth;
  }
  if ( !(v12 & 2) )
  {
    _S6_1 = v12 | 2;
    scale_y = 1.0 / (float)(signed int)UFG::UIScreenManager::s_instance->m_flashHeight;
  }
  Render::Poly::Poly(&poly, x, y, w, h, 0.0);
  Render::Poly::SetColour(&poly, Color);
  if ( UVs )
    Render::Poly::SetUVs(&poly, *UVs, UVs[1], UVs[2], UVs[3]);
  else
    Render::Poly::SetUVs(&poly, 0.0, 0.0, 1.0, 1.0);
  v13 = Render::View::CreateSimpleMaterial(TextureUID, RasterStateUID, AlphaStateUID, 0);
  if ( TransformMatrix )
  {
    v14 = poly.mVertices;
    v15 = (float)((float)((float)(poly.mVertices->mPosition.y * TransformMatrix->v1.y)
                        + (float)(poly.mVertices->mPosition.x * TransformMatrix->v0.y))
                + (float)(poly.mVertices->mPosition.z * TransformMatrix->v2.y))
        + TransformMatrix->v3.y;
    v16 = (float)((float)((float)(poly.mVertices->mPosition.y * TransformMatrix->v1.z)
                        + (float)(poly.mVertices->mPosition.x * TransformMatrix->v0.z))
                + (float)(poly.mVertices->mPosition.z * TransformMatrix->v2.z))
        + TransformMatrix->v3.z;
    poly.mVertices->mPosition.x = (float)((float)((float)(poly.mVertices->mPosition.x * TransformMatrix->v0.x)
                                                + (float)(poly.mVertices->mPosition.y * TransformMatrix->v1.x))
                                        + (float)(poly.mVertices->mPosition.z * TransformMatrix->v2.x))
                                + TransformMatrix->v3.x;
    v14->mPosition.y = v15;
    v14->mPosition.z = v16;
    v17 = poly.mVertices;
    v18 = (float)((float)((float)(poly.mVertices[1].mPosition.y * TransformMatrix->v1.y)
                        + (float)(poly.mVertices[1].mPosition.x * TransformMatrix->v0.y))
                + (float)(poly.mVertices[1].mPosition.z * TransformMatrix->v2.y))
        + TransformMatrix->v3.y;
    v19 = (float)((float)((float)(poly.mVertices[1].mPosition.y * TransformMatrix->v1.z)
                        + (float)(poly.mVertices[1].mPosition.x * TransformMatrix->v0.z))
                + (float)(poly.mVertices[1].mPosition.z * TransformMatrix->v2.z))
        + TransformMatrix->v3.z;
    poly.mVertices[1].mPosition.x = (float)((float)((float)(poly.mVertices[1].mPosition.x * TransformMatrix->v0.x)
                                                  + (float)(poly.mVertices[1].mPosition.y * TransformMatrix->v1.x))
                                          + (float)(poly.mVertices[1].mPosition.z * TransformMatrix->v2.x))
                                  + TransformMatrix->v3.x;
    v17[1].mPosition.y = v18;
    v17[1].mPosition.z = v19;
    v20 = poly.mVertices;
    v21 = (float)((float)((float)(poly.mVertices[2].mPosition.y * TransformMatrix->v1.y)
                        + (float)(poly.mVertices[2].mPosition.x * TransformMatrix->v0.y))
                + (float)(poly.mVertices[2].mPosition.z * TransformMatrix->v2.y))
        + TransformMatrix->v3.y;
    v22 = (float)((float)((float)(poly.mVertices[2].mPosition.y * TransformMatrix->v1.z)
                        + (float)(poly.mVertices[2].mPosition.x * TransformMatrix->v0.z))
                + (float)(poly.mVertices[2].mPosition.z * TransformMatrix->v2.z))
        + TransformMatrix->v3.z;
    poly.mVertices[2].mPosition.x = (float)((float)((float)(poly.mVertices[2].mPosition.x * TransformMatrix->v0.x)
                                                  + (float)(poly.mVertices[2].mPosition.y * TransformMatrix->v1.x))
                                          + (float)(poly.mVertices[2].mPosition.z * TransformMatrix->v2.x))
                                  + TransformMatrix->v3.x;
    v20[2].mPosition.y = v21;
    v20[2].mPosition.z = v22;
    v23 = poly.mVertices;
    v24 = (float)((float)((float)(poly.mVertices[3].mPosition.y * TransformMatrix->v1.y)
                        + (float)(poly.mVertices[3].mPosition.x * TransformMatrix->v0.y))
                + (float)(poly.mVertices[3].mPosition.z * TransformMatrix->v2.y))
        + TransformMatrix->v3.y;
    v25 = (float)((float)((float)(poly.mVertices[3].mPosition.y * TransformMatrix->v1.z)
                        + (float)(poly.mVertices[3].mPosition.x * TransformMatrix->v0.z))
                + (float)(poly.mVertices[3].mPosition.z * TransformMatrix->v2.z))
        + TransformMatrix->v3.z;
    poly.mVertices[3].mPosition.x = (float)((float)((float)(poly.mVertices[3].mPosition.x * TransformMatrix->v0.x)
                                                  + (float)(poly.mVertices[3].mPosition.y * TransformMatrix->v1.x))
                                          + (float)(poly.mVertices[3].mPosition.z * TransformMatrix->v2.x))
                                  + TransformMatrix->v3.x;
    v23[3].mPosition.y = v24;
    v23[3].mPosition.z = v25;
  }
  v26 = scale_x;
  poly.mVertices->mPosition.x = scale_x * poly.mVertices->mPosition.x;
  v27 = scale_y;
  poly.mVertices->mPosition.y = scale_y * poly.mVertices->mPosition.y;
  poly.mVertices[1].mPosition.x = v26 * poly.mVertices[1].mPosition.x;
  poly.mVertices[1].mPosition.y = v27 * poly.mVertices[1].mPosition.y;
  poly.mVertices[2].mPosition.x = v26 * poly.mVertices[2].mPosition.x;
  poly.mVertices[2].mPosition.y = v27 * poly.mVertices[2].mPosition.y;
  poly.mVertices[3].mPosition.x = v26 * poly.mVertices[3].mPosition.x;
  poly.mVertices[3].mPosition.y = v27 * poly.mVertices[3].mPosition.y;
  Render::View::Draw(v11, &poly, v13, 0i64);
}

// File Line: 98
// RVA: 0xC03C0
void __fastcall UFG::DrawUIRenderQuad(Render::View *view, UFG::UIRenderQuad *quad, UFG::qMatrix44 *viewportScaleMatrix, unsigned int RasterStateUID, float alpha, float scale)
{
  float v6; // xmm1_4
  Render::View *v7; // rsi
  UFG::qMatrix44 *v8; // rcx
  unsigned int v9; // edi
  UFG::UIRenderQuad *v10; // rbx
  float v11; // xmm6_4
  float h; // xmm6_4
  UFG::qMatrix44 *v13; // rax
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm0
  UFG::qVector4 v16; // xmm1
  UFG::qVector4 v17; // xmm1
  float v18; // xmm2_4
  UFG::qColour Color; // [rsp+60h] [rbp-A8h]
  UFG::qMatrix44 TransformMatrix; // [rsp+70h] [rbp-98h]
  __int64 v21; // [rsp+B0h] [rbp-58h]

  v6 = quad->Color.g;
  v7 = view;
  v8 = quad->Matrix;
  v9 = RasterStateUID;
  v10 = quad;
  v11 = quad->Size;
  Color.r = quad->Color.r;
  h = (float)(v11 * quad->Scale) * scale;
  Color.b = quad->Color.b;
  Color.g = v6;
  Color.a = alpha * quad->Color.a;
  if ( v8 )
  {
    v13 = UFG::qMatrix44::operator*(v8, (UFG::qMatrix44 *)&v21, viewportScaleMatrix);
    v14 = v13->v1;
    TransformMatrix.v0 = v13->v0;
    v15 = v13->v2;
    TransformMatrix.v1 = v14;
    v16 = v13->v3;
  }
  else
  {
    v17 = viewportScaleMatrix->v1;
    TransformMatrix.v0 = viewportScaleMatrix->v0;
    v15 = viewportScaleMatrix->v2;
    TransformMatrix.v1 = v17;
    v16 = viewportScaleMatrix->v3;
  }
  v18 = v10->Y;
  TransformMatrix.v2 = v15;
  TransformMatrix.v3 = v16;
  UFG::DrawColoredRect_Xform(
    v7,
    v10->X - (float)(h * 0.5),
    v18 - (float)(h * 0.5),
    h,
    h,
    &Color,
    v10->TextureID,
    v10->UVs,
    0xA3833FDE,
    v9,
    &TransformMatrix);
}

// File Line: 127
// RVA: 0xCBA10
void __usercall UFG::UIGetViewportScaleMatrix(UFG::qMatrix44 *ViewportScaleMatrix@<rcx>, UFG::UIScreen *screen@<rdx>, float a3@<xmm0>)
{
  UFG::qMatrix44 *v3; // rsi
  UFG::UIScreen *v4; // rdi
  __int64 v5; // rbx
  __int64 v6; // rdi
  __m128 v7; // xmm5
  __m128 v8; // xmm6
  __m128 v9; // xmm8
  __m128 v10; // xmm9
  __m128 v11; // xmm4
  __m128 v12; // xmm10
  __m128 v13; // xmm11
  __m128 v14; // xmm12
  __m128 v15; // xmm7
  __m128 v16; // xmm5
  __m128 v17; // xmm2
  UFG::qVector3 offset; // [rsp+20h] [rbp-D8h]
  UFG::qMatrix44 dest; // [rsp+30h] [rbp-C8h]
  UFG::qMatrix44 d; // [rsp+70h] [rbp-88h]
  __m128 v21; // [rsp+B8h] [rbp-40h]
  __m128 v22; // [rsp+C8h] [rbp-30h]
  __m128 v23; // [rsp+D8h] [rbp-20h]

  v3 = ViewportScaleMatrix;
  v4 = screen;
  v5 = ((__int64 (*)(void))screen->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)();
  v6 = ((__int64 (*)(void))v4->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)();
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 56i64))(v5);
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 48i64))(v6);
  offset.y = (float)(a3 * -1.0) * 0.5;
  offset.x = (float)(a3 * -1.0) * 0.5;
  offset.z = 0.0;
  UFG::qTranslationMatrix(&dest, &offset);
  offset.x = UFG::gUIViewportScaleH * UFG::gUIViewportScale;
  offset.y = UFG::gUIViewportScaleV * UFG::gUIViewportScale;
  LODWORD(offset.z) = (_DWORD)FLOAT_1_0;
  UFG::qScaleMatrix(&d, &offset);
  UFG::qInverseAffine((UFG::qMatrix44 *)((char *)&d + 56), &dest);
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 0), (__m128)d.v0), (__m128)0i64),
             _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 85), *(__m128 *)&d.v0.z)),
           _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 170), *(__m128 *)&d.v1.z)),
         _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 255), *(__m128 *)&d.v2.z));
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 0), (__m128)d.v0), (__m128)0i64),
             _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 85), *(__m128 *)&d.v0.z)),
           _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 170), *(__m128 *)&d.v1.z)),
         _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 255), *(__m128 *)&d.v2.z));
  v9 = *(__m128 *)&d.v3.z;
  v10 = v21;
  v11 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 0), (__m128)d.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 85), *(__m128 *)&d.v0.z)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 170), *(__m128 *)&d.v1.z)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 255), *(__m128 *)&d.v2.z));
  v12 = v22;
  v13 = v23;
  v14 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 255), *(__m128 *)&d.v2.z),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 0), (__m128)d.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 85), *(__m128 *)&d.v0.z)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 170), *(__m128 *)&d.v1.z)));
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), *(__m128 *)&d.v3.z), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v21)),
            _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v22)),
          _mm_mul_ps(_mm_shuffle_ps(v7, v7, 255), v23));
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), *(__m128 *)&d.v3.z), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), v21)),
            _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), v22)),
          _mm_mul_ps(_mm_shuffle_ps(v8, v8, 255), v23));
  v17 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), *(__m128 *)&d.v3.z), (__m128)0i64),
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v21));
  v3->v0 = (UFG::qVector4)v15;
  v3->v1 = (UFG::qVector4)v16;
  v3->v2 = (UFG::qVector4)_mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 255), v13),
                            _mm_add_ps(v17, _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v12)));
  v3->v3 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v9), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v10)),
                              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v12)),
                            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v13));
}

