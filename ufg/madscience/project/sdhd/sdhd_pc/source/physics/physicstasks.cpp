// File Line: 16
// RVA: 0x151A5E0
__int64 dynamic_initializer_for__gTaskFunctionDecl_MakeStaticSceneryInvisibleTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_MakeStaticSceneryInvisibleTask,
    &gTaskFunctionDeclData_MakeStaticSceneryInvisibleTask);
  return atexit(dynamic_atexit_destructor_for__gTaskFunctionDecl_MakeStaticSceneryInvisibleTask__);
}

// File Line: 21
// RVA: 0x4898D0
void __fastcall MakeStaticSceneryInvisibleTask(int worker_id, UFG::qMemoryStreamer *memory_streamer, void *mainMemSceneryGroup, void *sceneryToDisable, unsigned int sceneryGuid)
{
  unsigned int v5; // ebx
  __int64 v6; // rdx
  char *v7; // r11
  __int64 v8; // r10
  signed __int64 v9; // r8
  signed __int64 v10; // rcx
  __m128 v11; // xmm3
  float v12; // xmm0_4

  v5 = *((unsigned __int16 *)mainMemSceneryGroup + 45);
  v6 = 0i64;
  v7 = (char *)mainMemSceneryGroup;
  if ( *((_WORD *)mainMemSceneryGroup + 45) )
  {
    v8 = *((_QWORD *)mainMemSceneryGroup + 13);
    while ( 1 )
    {
      v9 = (signed __int64)(v8 ? &v7[v8 + 104] : 0i64);
      v10 = v9 + 96 * v6;
      if ( *(_DWORD *)v10 == sceneryGuid )
      {
        v11 = (__m128)*(unsigned int *)(v10 + 84);
        v12 = *(float *)(v10 + 88) - *((float *)sceneryToDisable + 6);
        v11.m128_f32[0] = (float)((float)((float)((float)(v11.m128_f32[0] - *((float *)sceneryToDisable + 5))
                                                * (float)(v11.m128_f32[0] - *((float *)sceneryToDisable + 5)))
                                        + (float)((float)(*(float *)(v10 + 80) - *((float *)sceneryToDisable + 4))
                                                * (float)(*(float *)(v10 + 80) - *((float *)sceneryToDisable + 4))))
                                + (float)(v12 * v12))
                        + (float)((float)(*(float *)(v10 + 92) - 1.0) * (float)(*(float *)(v10 + 92) - 1.0));
        if ( COERCE_FLOAT(_mm_sqrt_ps(v11)) <= 0.050000001 )
          break;
      }
      v6 = (unsigned int)(v6 + 1);
      if ( (unsigned int)v6 >= v5 )
        return;
    }
    *((_QWORD *)sceneryToDisable + 4) = v7;
    *((_DWORD *)sceneryToDisable + 10) = v6;
  }
}

