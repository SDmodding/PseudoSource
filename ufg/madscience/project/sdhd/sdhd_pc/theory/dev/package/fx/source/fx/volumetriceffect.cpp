// File Line: 18
// RVA: 0x146B9C0
__int64 Render::_dynamic_initializer_for__gVolumetricEffectManager__()
{
  return atexit(Render::_dynamic_atexit_destructor_for__gVolumetricEffectManager__);
}

// File Line: 42
// RVA: 0x1C72B0
void __fastcall Render::VolumetricEffectManager::AddVolume(Render::VolumetricEffectManager *this, Render::VolumetricEffect *pVolume)
{
  __int64 v2; // rsi
  UFG::qArray<Render::VolumetricEffect *,0> *v3; // rdi
  Render::VolumetricEffect *v4; // rbp
  unsigned int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  Render::VolumetricEffect **v8; // rax
  CullManager *v9; // rax
  CullInfo *v10; // rax

  v2 = this->mVolumes.size;
  v3 = &this->mVolumes;
  v4 = pVolume;
  v5 = this->mVolumes.capacity;
  v6 = v2 + 1;
  if ( (signed int)v2 + 1 > v5 )
  {
    if ( v5 )
      v7 = 2 * v5;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = v2 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mVolumes,
      v7,
      "qArray.Add");
  }
  v8 = v3->p;
  v3->size = v6;
  v8[v2] = v4;
  v9 = CullManager::Instance();
  CullManager::AllocPersistentCullInfo(v9, &v4->cull_results, &v4->cull_info, 0i64, 0i64, 0i64);
  v10 = v4->cull_info;
  v10->mpLocalWorld = &v4->mTransform.v0.x;
  *(_DWORD *)&v10->mIsLocalWorldIdentity = 0;
  *(_DWORD *)&v10->mPixelScaleBias = -130072;
  v10->mAABBMin[0] = -1.0;
  v10->mAABBMin[1] = -1.0;
  v10->mAABBMin[2] = -1.0;
  v10->mAABBMax[0] = 1.0;
  v10->mAABBMax[1] = 1.0;
  v10->mAABBMax[2] = 1.0;
}

// File Line: 61
// RVA: 0x1D2A30
void __fastcall Render::VolumetricEffectManager::RemoveVolume(Render::VolumetricEffectManager *this, Render::VolumetricEffect *pVolume)
{
  Render::VolumetricEffectManager *v2; // rbx
  unsigned int v3; // ecx
  signed __int64 v4; // rax
  Render::VolumetricEffect *v5; // rdi
  Render::VolumetricEffect **v6; // r8
  signed __int64 v7; // rsi
  CullManager *v8; // rax
  unsigned int v9; // eax
  unsigned int v10; // eax

  v2 = this;
  v3 = this->mVolumes.size;
  v4 = 0i64;
  v5 = pVolume;
  if ( v3 )
  {
    v6 = v2->mVolumes.p;
    while ( *v6 != pVolume )
    {
      v4 = (unsigned int)(v4 + 1);
      ++v6;
      if ( (unsigned int)v4 >= v3 )
        return;
    }
    v7 = v4;
    if ( v2->mVolumes.p[v4]->cull_info )
    {
      v8 = CullManager::Instance();
      CullManager::FreePersistentCullInfo(v8, v5->cull_results, v5->cull_info);
      v5->cull_results = 0i64;
      v5->cull_info = 0i64;
    }
    v9 = v2->mVolumes.size;
    if ( v9 > 1 )
      v2->mVolumes.p[v7] = v2->mVolumes.p[v9 - 1];
    v10 = v2->mVolumes.size;
    if ( v10 > 1 )
      v2->mVolumes.size = v10 - 1;
    else
      v2->mVolumes.size = 0;
  }
}

// File Line: 82
// RVA: 0x1CD350
__int64 __fastcall Render::VolumetricEffectManager::GetVolumetricEffects(Render::VolumetricEffectManager *this, Render::VolumetricEffect **pBuffer, unsigned int maxVolumes)
{
  __int64 result; // rax
  unsigned int v4; // er10
  __int64 v5; // r8

  result = 0i64;
  v4 = maxVolumes;
  if ( pBuffer && this->mEnabled && this->mVolumes.size > 0 )
  {
    do
    {
      if ( (unsigned int)result >= v4 )
        break;
      v5 = result;
      result = (unsigned int)(result + 1);
      pBuffer[v5] = this->mVolumes.p[v5];
    }
    while ( (unsigned int)result < this->mVolumes.size );
  }
  return result;
}

