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

  result = UFG::qStringHashUpper32("SIMPLE", -1);
  UFG::gUIshader_Simple_UID = result;
  return result;
}

// File Line: 41
// RVA: 0x145E690
__int64 UFG::_dynamic_initializer_for__gUIshader_Punch_Simple_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("SIMPLEPUNCH", -1);
  UFG::gUIshader_Punch_Simple_UID = result;
  return result;
}

// File Line: 59
// RVA: 0xBFF80
void __fastcall UFG::DrawColoredRect_Xform(
        Render::View *view,
        float x,
        float y,
        float w,
        float h,
        UFG::qColour *Color,
        unsigned int TextureUID,
        float *UVs,
        unsigned int AlphaStateUID,
        unsigned int RasterStateUID,
        UFG::qMatrix44 *TransformMatrix)
{
  unsigned int v12; // r8d
  Illusion::Material *SimpleMaterial; // r8
  Render::vDynamic *mVertices; // rcx
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
  Render::Poly poly; // [rsp+30h] [rbp-38h] BYREF
  __int64 v29; // [rsp+38h] [rbp-30h]

  v29 = -2i64;
  v12 = _S6_1;
  if ( (_S6_1 & 1) == 0 )
  {
    v12 = _S6_1 | 1;
    _S6_1 |= 1u;
    scale_x = 1.0 / (float)(int)UFG::UIScreenManager::s_instance->m_flashWidth;
  }
  if ( (v12 & 2) == 0 )
  {
    _S6_1 = v12 | 2;
    scale_y = 1.0 / (float)(int)UFG::UIScreenManager::s_instance->m_flashHeight;
  }
  Render::Poly::Poly(&poly, x, y, w, h, 0.0);
  Render::Poly::SetColour(&poly, Color);
  if ( UVs )
    Render::Poly::SetUVs(&poly, *UVs, UVs[1], UVs[2], UVs[3]);
  else
    Render::Poly::SetUVs(&poly, 0.0, 0.0, 1.0, 1.0);
  SimpleMaterial = Render::View::CreateSimpleMaterial(TextureUID, RasterStateUID, AlphaStateUID, 0);
  if ( TransformMatrix )
  {
    mVertices = poly.mVertices;
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
    mVertices->mPosition.y = v15;
    mVertices->mPosition.z = v16;
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
  Render::View::Draw(view, &poly, SimpleMaterial, 0i64);
}

// File Line: 98
// RVA: 0xC03C0
void __fastcall UFG::DrawUIRenderQuad(
        Render::View *view,
        UFG::UIRenderQuad *quad,
        UFG::qMatrix44 *viewportScaleMatrix,
        unsigned int RasterStateUID,
        float alpha,
        float scale)
{
  float g; // xmm1_4
  UFG::qMatrix44 *Matrix; // rcx
  float Size; // xmm6_4
  float h; // xmm6_4
  UFG::qMatrix44 *v13; // rax
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm0
  UFG::qVector4 v16; // xmm1
  UFG::qVector4 v17; // xmm1
  float Y; // xmm2_4
  UFG::qColour Color; // [rsp+60h] [rbp-A8h] BYREF
  UFG::qMatrix44 TransformMatrix; // [rsp+70h] [rbp-98h] BYREF
  UFG::qMatrix44 v21; // [rsp+B0h] [rbp-58h] BYREF

  g = quad->Color.g;
  Matrix = quad->Matrix;
  Size = quad->Size;
  Color.r = quad->Color.r;
  h = (float)(Size * quad->Scale) * scale;
  Color.b = quad->Color.b;
  Color.g = g;
  Color.a = alpha * quad->Color.a;
  if ( Matrix )
  {
    v13 = UFG::qMatrix44::operator*(Matrix, &v21, viewportScaleMatrix);
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
  Y = quad->Y;
  TransformMatrix.v2 = v15;
  TransformMatrix.v3 = v16;
  UFG::DrawColoredRect_Xform(
    view,
    quad->X - (float)(h * 0.5),
    Y - (float)(h * 0.5),
    h,
    h,
    &Color,
    quad->TextureID,
    quad->UVs,
    0xA3833FDE,
    RasterStateUID,
    &TransformMatrix);
}

// File Line: 127
// RVA: 0xCBA10
void __fastcall UFG::UIGetViewportScaleMatrix(UFG::qMatrix44 *ViewportScaleMatrix, UFG::UIScreen *screen)
{
  __int64 v4; // rbx
  __int64 v5; // rdi
  double v6; // xmm0_8
  float v7; // xmm8_4
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  UFG::qVector4 v10; // xmm8
  UFG::qVector4 v11; // xmm9
  __m128 v12; // xmm4
  UFG::qVector4 v13; // xmm10
  UFG::qVector4 v14; // xmm11
  __m128 v15; // xmm12
  UFG::qVector4 v16; // xmm7
  UFG::qVector4 v17; // xmm5
  __m128 v18; // xmm2
  UFG::qVector3 offset; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qMatrix44 dest; // [rsp+30h] [rbp-C8h] BYREF
  _BYTE d[24]; // [rsp+70h] [rbp-88h] BYREF
  __m128 d_24; // [rsp+88h] [rbp-70h]
  __m128 d_40; // [rsp+98h] [rbp-60h]
  UFG::qMatrix44 d_56; // [rsp+A8h] [rbp-50h] BYREF

  v4 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))screen->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)(screen->mRenderable->m_movie.pObject);
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))screen->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)(screen->mRenderable->m_movie.pObject);
  v6 = (*(double (__fastcall **)(__int64))(*(_QWORD *)v4 + 56i64))(v4);
  v7 = (float)(*(float *)&v6 * -1.0) * 0.5;
  *(float *)&v6 = (*(float (__fastcall **)(__int64))(*(_QWORD *)v5 + 48i64))(v5);
  offset.y = v7;
  offset.x = (float)(*(float *)&v6 * -1.0) * 0.5;
  offset.z = 0.0;
  UFG::qTranslationMatrix(&dest, &offset);
  offset.x = UFG::gUIViewportScaleH * UFG::gUIViewportScale;
  offset.y = UFG::gUIViewportScaleV * UFG::gUIViewportScale;
  LODWORD(offset.z) = (_DWORD)FLOAT_1_0;
  UFG::qScaleMatrix((UFG::qMatrix44 *)d, &offset);
  UFG::qInverseAffine(&d_56, &dest);
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 0), *(__m128 *)d), (__m128)0i64),
             _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 85), *(__m128 *)&d[8])),
           _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 170), d_24)),
         _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 255), d_40));
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 0), *(__m128 *)d), (__m128)0i64),
             _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 85), *(__m128 *)&d[8])),
           _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 170), d_24)),
         _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 255), d_40));
  v10 = d_56.v0;
  v11 = d_56.v1;
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 0), *(__m128 *)d), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 85), *(__m128 *)&d[8])),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 170), d_24)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 255), d_40));
  v13 = d_56.v2;
  v14 = d_56.v3;
  v15 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 255), d_40),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 0), *(__m128 *)d), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 85), *(__m128 *)&d[8])),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 170), d_24)));
  v16 = (UFG::qVector4)_mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), (__m128)d_56.v0), (__m128)0i64),
                             _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), (__m128)d_56.v1)),
                           _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), (__m128)d_56.v2)),
                         _mm_mul_ps(_mm_shuffle_ps(v8, v8, 255), (__m128)d_56.v3));
  v17 = (UFG::qVector4)_mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), (__m128)d_56.v0), (__m128)0i64),
                             _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), (__m128)d_56.v1)),
                           _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), (__m128)d_56.v2)),
                         _mm_mul_ps(_mm_shuffle_ps(v9, v9, 255), (__m128)d_56.v3));
  v18 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), (__m128)d_56.v0), (__m128)0i64),
          _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), (__m128)d_56.v1));
  ViewportScaleMatrix->v0 = v16;
  ViewportScaleMatrix->v1 = v17;
  ViewportScaleMatrix->v2 = (UFG::qVector4)_mm_add_ps(
                                             _mm_mul_ps(_mm_shuffle_ps(v12, v12, 255), (__m128)v14),
                                             _mm_add_ps(v18, _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), (__m128)v13)));
  ViewportScaleMatrix->v3 = (UFG::qVector4)_mm_add_ps(
                                             _mm_add_ps(
                                               _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), (__m128)v10),
                                                   (__m128)0i64),
                                                 _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), (__m128)v11)),
                                               _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), (__m128)v13)),
                                             _mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), (__m128)v14));
}

