// File Line: 18
// RVA: 0x146B9C0
__int64 Render::_dynamic_initializer_for__gVolumetricEffectManager__()
{
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gVolumetricEffectManager__);
}

// File Line: 42
// RVA: 0x1C72B0
void __fastcall Render::VolumetricEffectManager::AddVolume(
        Render::VolumetricEffectManager *this,
        Render::VolumetricEffect *pVolume)
{
  __int64 size; // rsi
  UFG::qArray<Render::VolumetricEffect *,0> *p_mVolumes; // rdi
  unsigned int capacity; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  Render::VolumetricEffect **p; // rax
  CullManager *v9; // rax
  CullInfo *cull_info; // rax

  size = this->mVolumes.size;
  p_mVolumes = &this->mVolumes;
  capacity = this->mVolumes.capacity;
  v6 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mVolumes,
      v7,
      "qArray.Add");
  }
  p = p_mVolumes->p;
  p_mVolumes->size = v6;
  p[size] = pVolume;
  v9 = CullManager::Instance();
  CullManager::AllocPersistentCullInfo(v9, &pVolume->cull_results, &pVolume->cull_info, 0i64, 0i64, 0i64);
  cull_info = pVolume->cull_info;
  cull_info->mpLocalWorld = &pVolume->mTransform.v0.x;
  *(_DWORD *)&cull_info->mIsLocalWorldIdentity = 0;
  *(_DWORD *)&cull_info->mPixelScaleBias = -130072;
  cull_info->mAABBMin[0] = -1.0;
  cull_info->mAABBMin[1] = -1.0;
  cull_info->mAABBMin[2] = -1.0;
  cull_info->mAABBMax[0] = 1.0;
  cull_info->mAABBMax[1] = 1.0;
  cull_info->mAABBMax[2] = 1.0;
}

// File Line: 61
// RVA: 0x1D2A30
void __fastcall Render::VolumetricEffectManager::RemoveVolume(
        Render::VolumetricEffectManager *this,
        Render::VolumetricEffect *pVolume)
{
  unsigned int size; // ecx
  __int64 v4; // rax
  Render::VolumetricEffect **i; // r8
  __int64 v7; // rsi
  CullManager *v8; // rax
  unsigned int v9; // eax
  unsigned int v10; // eax

  size = this->mVolumes.size;
  v4 = 0i64;
  if ( size )
  {
    for ( i = this->mVolumes.p; *i != pVolume; ++i )
    {
      v4 = (unsigned int)(v4 + 1);
      if ( (unsigned int)v4 >= size )
        return;
    }
    v7 = v4;
    if ( this->mVolumes.p[v4]->cull_info )
    {
      v8 = CullManager::Instance();
      CullManager::FreePersistentCullInfo(v8, pVolume->cull_results, pVolume->cull_info);
      pVolume->cull_results = 0i64;
      pVolume->cull_info = 0i64;
    }
    v9 = this->mVolumes.size;
    if ( v9 > 1 )
      this->mVolumes.p[v7] = this->mVolumes.p[v9 - 1];
    v10 = this->mVolumes.size;
    if ( v10 > 1 )
      this->mVolumes.size = v10 - 1;
    else
      this->mVolumes.size = 0;
  }
}

// File Line: 82
// RVA: 0x1CD350
__int64 __fastcall Render::VolumetricEffectManager::GetVolumetricEffects(
        Render::VolumetricEffectManager *this,
        Render::VolumetricEffect **pBuffer,
        unsigned int maxVolumes)
{
  __int64 result; // rax
  __int64 v5; // r8

  result = 0i64;
  if ( pBuffer && this->mEnabled && this->mVolumes.size )
  {
    do
    {
      if ( (unsigned int)result >= maxVolumes )
        break;
      v5 = result;
      result = (unsigned int)(result + 1);
      pBuffer[v5] = this->mVolumes.p[v5];
    }
    while ( (unsigned int)result < this->mVolumes.size );
  }
  return result;
}

