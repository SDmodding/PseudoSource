// File Line: 48
// RVA: 0x6A29E0
void __fastcall UFG::RenderContextPlat::CreateTargets(
        UFG::RenderContextPlat *this,
        const char *description,
        int scene_output_width,
        int scene_output_height,
        unsigned int reflection_width,
        unsigned int reflection_height,
        unsigned int envmap_size,
        bool bRequireReadAccess)
{
  UFG::qString *v9; // rax
  Illusion::CreateTargetParams v10; // [rsp+20h] [rbp-B9h] BYREF
  __int64 v11; // [rsp+D0h] [rbp-9h]
  UFG::qString result; // [rsp+D8h] [rbp-1h] BYREF

  v11 = -2i64;
  if ( UFG::gEnableHalfResolutionGbuffer )
  {
    this->mRenderContext->mGBufferWidth = (31 - (int)(float)((float)scene_output_width * -0.5)) & 0xFFFFFFE0;
    this->mRenderContext->mGBufferHeight = (31 - (int)(float)((float)scene_output_height * -0.5)) & 0xFFFFFFE0;
    v9 = UFG::qString::FormatEx(&result, "GBuffers%s", description);
    UFG::qString::qString(&v10.name, v9->mData);
    *(_QWORD *)&v10.num_mrt = 1i64;
    *(_QWORD *)&v10.width = 0i64;
    v10.depth = 1;
    v10.array_size = 1;
    *(_DWORD *)v10.mrt_formats = -1;
    v10.target_flags = 0;
    v10.num_mips = 1;
    memset(v10.textures, 0, 85);
    UFG::qString::~qString(&result);
    *(_QWORD *)&v10.width = *(_QWORD *)&this->mRenderContext->mGBufferWidth;
    *(_WORD *)v10.mrt_formats = 0;
    v10.mrt_formats[2] = 0;
    v10.num_mrt = 3;
    v10.target_flags = (bRequireReadAccess ? 0x4000 : 0) | 0x10303;
    this->mRenderContext->mGBufferTarget = Illusion::CreateTarget(&v10);
    UFG::qString::~qString(&v10.name);
  }
}

