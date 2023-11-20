// File Line: 48
// RVA: 0x6A29E0
void __fastcall UFG::RenderContextPlat::CreateTargets(UFG::RenderContextPlat *this, const char *description, unsigned int scene_output_width, unsigned int scene_output_height, unsigned int reflection_width, unsigned int reflection_height, unsigned int envmap_size, bool bRequireReadAccess)
{
  UFG::RenderContextPlat *v8; // rbx
  UFG::qString *v9; // rax
  UFG::RenderContext *v10; // rcx
  UFG::qString v11; // [rsp+20h] [rbp-B9h]
  __int64 v12; // [rsp+48h] [rbp-91h]
  int v13; // [rsp+50h] [rbp-89h]
  int v14; // [rsp+54h] [rbp-85h]
  int v15; // [rsp+58h] [rbp-81h]
  __int64 v16; // [rsp+5Ch] [rbp-7Dh]
  int v17; // [rsp+64h] [rbp-75h]
  int v18; // [rsp+68h] [rbp-71h]
  __int128 v19; // [rsp+70h] [rbp-69h]
  __int128 v20; // [rsp+80h] [rbp-59h]
  __int64 v21; // [rsp+90h] [rbp-49h]
  __int64 v22; // [rsp+98h] [rbp-41h]
  __int64 v23; // [rsp+A0h] [rbp-39h]
  __int64 v24; // [rsp+A8h] [rbp-31h]
  __int64 v25; // [rsp+B0h] [rbp-29h]
  __int64 v26; // [rsp+B8h] [rbp-21h]
  int v27; // [rsp+C0h] [rbp-19h]
  char v28; // [rsp+C4h] [rbp-15h]
  __int64 v29; // [rsp+D0h] [rbp-9h]
  UFG::qString result; // [rsp+D8h] [rbp-1h]

  v29 = -2i64;
  v8 = this;
  if ( UFG::gEnableHalfResolutionGbuffer )
  {
    this->mRenderContext->mGBufferWidth = (31 - (signed int)(float)((float)(signed int)scene_output_width * -0.5)) & 0xFFFFFFE0;
    this->mRenderContext->mGBufferHeight = (31 - (signed int)(float)((float)(signed int)scene_output_height * -0.5)) & 0xFFFFFFE0;
    v9 = UFG::qString::FormatEx(&result, "GBuffers%s", description);
    UFG::qString::qString(&v11, v9->mData);
    v16 = 1i64;
    v12 = 0i64;
    v13 = 1;
    v14 = 1;
    v15 = -1;
    v17 = 0;
    v18 = 1;
    _mm_store_si128((__m128i *)&v19, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v20, (__m128i)0i64);
    v21 = 0i64;
    v22 = 0i64;
    v23 = 0i64;
    v24 = 0i64;
    v25 = 0i64;
    v26 = 0i64;
    v27 = 0;
    v28 = 0;
    UFG::qString::~qString(&result);
    v10 = v8->mRenderContext;
    LODWORD(v12) = v8->mRenderContext->mGBufferWidth;
    HIDWORD(v12) = v10->mGBufferHeight;
    LOWORD(v15) = 0;
    BYTE2(v15) = 0;
    LODWORD(v16) = 3;
    v17 = (bRequireReadAccess != 0 ? 0x4000 : 0) | 0x10303;
    v8->mRenderContext->mGBufferTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v11);
    UFG::qString::~qString(&v11);
  }
}

