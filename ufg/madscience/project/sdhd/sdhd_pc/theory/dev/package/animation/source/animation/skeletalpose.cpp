// File Line: 41
// RVA: 0x146AC00
__int64 dynamic_initializer_for__gDrawSkeletonBoneNameFilter__()
{
  UFG::qString::qString(&gDrawSkeletonBoneNameFilter);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gDrawSkeletonBoneNameFilter__);
}

// File Line: 46
// RVA: 0x146AD80
__int64 dynamic_initializer_for__s_uDirectionUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Direction", -1);
  s_uDirectionUID_0 = result;
  return result;
}

// File Line: 47
// RVA: 0x146ADA0
__int64 dynamic_initializer_for__s_uSync01UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Sync01", -1);
  s_uSync01UID_0 = result;
  return result;
}

// File Line: 48
// RVA: 0x146ACE0
__int64 dynamic_initializer_for__s_uBalanceUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Balance", -1);
  s_uBalanceUID_0 = result;
  return result;
}

// File Line: 50
// RVA: 0x146AD40
__int64 dynamic_initializer_for__s_uBip01_R_ClavicleUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R Clavicle", -1);
  s_uBip01_R_ClavicleUID_0 = result;
  return result;
}

// File Line: 51
// RVA: 0x146AD60
__int64 dynamic_initializer_for__s_uBip01_R_UpperArmUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R UpperArm", -1);
  s_uBip01_R_UpperArmUID_0 = result;
  return result;
}

// File Line: 52
// RVA: 0x146AE20
__int64 dynamic_initializer_for__s_ur_upperarm_twistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("r_upperarm_twist", -1);
  s_ur_upperarm_twistUID_0 = result;
  return result;
}

// File Line: 53
// RVA: 0x146AE00
__int64 dynamic_initializer_for__s_ur_shoulder_jointUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("r_shoulder_joint", -1);
  s_ur_shoulder_jointUID_0 = result;
  return result;
}

// File Line: 55
// RVA: 0x146AD00
__int64 dynamic_initializer_for__s_uBip01_L_ClavicleUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L Clavicle", -1);
  s_uBip01_L_ClavicleUID_0 = result;
  return result;
}

// File Line: 56
// RVA: 0x146AD20
__int64 dynamic_initializer_for__s_uBip01_L_UpperArmUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L UpperArm", -1);
  s_uBip01_L_UpperArmUID_0 = result;
  return result;
}

// File Line: 57
// RVA: 0x146ADE0
__int64 dynamic_initializer_for__s_ul_upperarm_twistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("l_upperarm_twist", -1);
  s_ul_upperarm_twistUID_0 = result;
  return result;
}

// File Line: 58
// RVA: 0x146ADC0
__int64 dynamic_initializer_for__s_ul_shoulder_jointUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("l_shoulder_joint", -1);
  s_ul_shoulder_jointUID_0 = result;
  return result;
}

// File Line: 60
// RVA: 0x146ACA0
__int64 dynamic_initializer_for__s_R_Forearm_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R Forearm", -1);
  s_R_Forearm_UID_0 = result;
  return result;
}

// File Line: 61
// RVA: 0x146ACC0
__int64 dynamic_initializer_for__s_R_Hand_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R Hand", -1);
  s_R_Hand_UID_0 = result;
  return result;
}

// File Line: 62
// RVA: 0x146AC80
__int64 dynamic_initializer_for__s_R_ForeTwist_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R ForeTwist", -1);
  s_R_ForeTwist_UID_0 = result;
  return result;
}

// File Line: 64
// RVA: 0x146AC40
__int64 dynamic_initializer_for__s_L_Forearm_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L Forearm", -1);
  s_L_Forearm_UID_0 = result;
  return result;
}

// File Line: 65
// RVA: 0x146AC60
__int64 dynamic_initializer_for__s_L_Hand_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L Hand", -1);
  s_L_Hand_UID_0 = result;
  return result;
}

// File Line: 66
// RVA: 0x146AC20
__int64 dynamic_initializer_for__s_L_ForeTwist_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L ForeTwist", -1);
  s_L_ForeTwist_UID_0 = result;
  return result;
}

// File Line: 74
// RVA: 0x1B9500
void __fastcall SkeletalPose::SkeletalPose(SkeletalPose *this, unsigned int rigUid)
{
  UFG::RigHandle *p_mRigHandle; // rdi
  UFG::qVector4 v5; // xmm3
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceData *mData; // rdi
  __int64 v9; // rsi
  char v10; // dl
  char v11; // cl
  _QWORD **Value; // rax
  __int64 v13; // rax
  hkaPose *v14; // r15
  int v15; // edi
  int v16; // ebp
  int v17; // eax
  int v18; // eax
  int v19; // r9d
  int v20; // eax
  int v21; // eax
  int v22; // r9d
  int v23; // eax
  int v24; // eax
  int v25; // r9d
  int m_size; // ebp
  int v27; // r9d
  int v28; // eax
  int v29; // eax
  int v30; // r9d
  int v31; // edx
  float *v32; // rdi
  __int64 v33; // rcx
  char v34; // al
  hkResult v35; // [rsp+30h] [rbp-68h] BYREF
  hkResult v36; // [rsp+34h] [rbp-64h] BYREF
  hkResult v37; // [rsp+38h] [rbp-60h] BYREF
  hkResult v38; // [rsp+3Ch] [rbp-5Ch] BYREF
  hkResult v39; // [rsp+40h] [rbp-58h] BYREF
  hkResult v40; // [rsp+44h] [rbp-54h] BYREF
  __int64 v41; // [rsp+48h] [rbp-50h]
  __int64 v42; // [rsp+50h] [rbp-48h]
  UFG::RigHandle *result; // [rsp+B0h] [rbp+18h] BYREF
  hkResult v44; // [rsp+B8h] [rbp+20h] BYREF

  v41 = -2i64;
  this->mRootTransformNode.mPrev = &this->mRootTransformNode;
  this->mRootTransformNode.mNext = &this->mRootTransformNode;
  this->mRootTransformNode.m_pPointer = 0i64;
  p_mRigHandle = &this->mRigHandle;
  result = &this->mRigHandle;
  UFG::qResourceHandle::qResourceHandle(&this->mRigHandle);
  p_mRigHandle->mLoadFunction = 0i64;
  p_mRigHandle->mUnloadFunction = 0i64;
  p_mRigHandle->mUserData = 0i64;
  p_mRigHandle->mUFGSkeleton = 0i64;
  v5 = 0i64;
  this->mRootQsMatrix.m_translation = 0i64;
  this->mRootQsMatrix.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  this->mRootQsMatrix.m_scale = (hkVector4f)query.m_quad;
  v5.x = (float)1;
  this->mRootMatrix44.v0 = v5;
  this->mRootMatrix44.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v5, (__m128)v5, 81);
  this->mRootMatrix44.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v5, (__m128)v5, 69);
  this->mRootMatrix44.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v5, (__m128)v5, 21);
  this->mIsRootDirty = 0;
  this->mCachedTransformChangeID = -1;
  Inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(p_mRigHandle, 0x39BC0A7Eu, rigUid, Inventory);
  this->mRigHandle.mUnloadFunction = SkeletalPose::RigUnloadedCallback;
  this->mRigHandle.mLoadFunction = SkeletalPose::RigLoadedCallback;
  this->mRigHandle.mUserData = this;
  mData = this->mRigHandle.mData;
  v9 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v10 = ++*(_BYTE *)(v9 + 80);
  *(_DWORD *)(v9 + 4i64 * v10) = 2;
  *(_QWORD *)(v9 + 8i64 * v10 + 16) = "hkaPose";
  *(_QWORD *)(v9 + 8i64 * v10 + 48) = 0i64;
  v11 = *(_BYTE *)(v9 + 81);
  if ( v10 > v11 )
    v11 = v10;
  *(_BYTE *)(v9 + 81) = v11;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  v14 = (hkaPose *)v13;
  v42 = v13;
  if ( v13 )
  {
    *(_QWORD *)v13 = mData[3].mNode.mParent->mChild[0];
    *(_QWORD *)(v13 + 8) = 0i64;
    *(_DWORD *)(v13 + 16) = 0;
    *(_DWORD *)(v13 + 20) = 0x80000000;
    *(_QWORD *)(v13 + 24) = 0i64;
    *(_DWORD *)(v13 + 32) = 0;
    *(_DWORD *)(v13 + 36) = 0x80000000;
    *(_QWORD *)(v13 + 40) = 0i64;
    *(_DWORD *)(v13 + 48) = 0;
    *(_DWORD *)(v13 + 52) = 0x80000000;
    *(_WORD *)(v13 + 56) = 0;
    *(_QWORD *)(v13 + 64) = 0i64;
    *(_DWORD *)(v13 + 72) = 0;
    *(_DWORD *)(v13 + 76) = 0x80000000;
    v15 = *(_DWORD *)(*(_QWORD *)v13 + 48i64);
    v16 = (v15 + 3) & 0xFFFFFFFC;
    if ( (*(_DWORD *)(v13 + 36) & 0x3FFFFFFF) >= v16 )
      LODWORD(result) = 0;
    else
      hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, (void *)(v13 + 24), v16, 48);
    if ( (v14->m_localPose.m_capacityAndFlags & 0x3FFFFFFF) >= v16 )
      v44.m_enum = HK_SUCCESS;
    else
      hkArrayUtil::_reserve(&v44, &hkContainerHeapAllocator::s_alloc, &v14->m_localPose, v16, 48);
    if ( (v14->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) >= v16 )
      v35.m_enum = HK_SUCCESS;
    else
      hkArrayUtil::_reserve(&v35, &hkContainerHeapAllocator::s_alloc, &v14->m_boneFlags, v16, 4);
    v17 = v14->m_modelPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v17 >= v15 )
    {
      v36.m_enum = HK_SUCCESS;
    }
    else
    {
      v18 = 2 * v17;
      v19 = v15;
      if ( v15 < v18 )
        v19 = v18;
      hkArrayUtil::_reserve(&v36, &hkContainerHeapAllocator::s_alloc, &v14->m_modelPose, v19, 48);
    }
    v14->m_modelPose.m_size = v15;
    v20 = v14->m_localPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v20 >= v15 )
    {
      v37.m_enum = HK_SUCCESS;
    }
    else
    {
      v21 = 2 * v20;
      v22 = v15;
      if ( v15 < v21 )
        v22 = v21;
      hkArrayUtil::_reserve(&v37, &hkContainerHeapAllocator::s_alloc, &v14->m_localPose, v22, 48);
    }
    v14->m_localPose.m_size = v15;
    v23 = v14->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v23 >= v15 )
    {
      v38.m_enum = HK_SUCCESS;
    }
    else
    {
      v24 = 2 * v23;
      v25 = v15;
      if ( v15 < v24 )
        v25 = v24;
      hkArrayUtil::_reserve(&v38, &hkContainerHeapAllocator::s_alloc, &v14->m_boneFlags, v25, 4);
    }
    v14->m_boneFlags.m_size = v15;
    m_size = v14->m_skeleton->m_floatSlots.m_size;
    v27 = (m_size + 3) & 0xFFFFFFFC;
    if ( (v14->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) >= v27 )
      v39.m_enum = HK_SUCCESS;
    else
      hkArrayUtil::_reserve(&v39, &hkContainerHeapAllocator::s_alloc, &v14->m_floatSlotValues, v27, 4);
    v28 = v14->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v28 >= m_size )
    {
      v40.m_enum = HK_SUCCESS;
    }
    else
    {
      v29 = 2 * v28;
      v30 = m_size;
      if ( m_size < v29 )
        v30 = v29;
      hkArrayUtil::_reserve(&v40, &hkContainerHeapAllocator::s_alloc, &v14->m_floatSlotValues, v30, 4);
    }
    v31 = m_size - v14->m_floatSlotValues.m_size;
    v32 = &v14->m_floatSlotValues.m_data[v14->m_floatSlotValues.m_size];
    v33 = v31;
    if ( v31 > 0 )
    {
      while ( v33 )
      {
        *v32++ = 0.0;
        --v33;
      }
    }
    v14->m_floatSlotValues.m_size = m_size;
  }
  else
  {
    v14 = 0i64;
  }
  this->mHavokPose = v14;
  v34 = *(_BYTE *)(v9 + 80);
  if ( v34 > 0 )
  {
    *(_BYTE *)(v9 + 80) = v34 - 1;
  }
  else
  {
    *(_BYTE *)(v9 + 80) = 0;
    *(_DWORD *)v9 = 3;
    *(_QWORD *)(v9 + 16) = 0i64;
    *(_QWORD *)(v9 + 48) = 0i64;
  }
  this->mBoneUpdateCount = -1;
}

// File Line: 96
// RVA: 0x1B9970
void __fastcall SkeletalPose::SkeletalPose(SkeletalPose *this, UFG::RigResource *rig)
{
  UFG::RigHandle *p_mRigHandle; // rdi
  UFG::qVector4 v5; // xmm3
  unsigned int mUID; // esi
  UFG::qResourceInventory *inventory; // rax
  UFG::qResourceWarehouse *v8; // rax
  __int64 v9; // rsi
  char v10; // dl
  char v11; // cl
  _QWORD **Value; // rax
  __int64 v13; // rax
  hkaPose *v14; // r14
  int v15; // edi
  int v16; // ebp
  int v17; // eax
  int v18; // eax
  int v19; // r9d
  int v20; // eax
  int v21; // eax
  int v22; // r9d
  int v23; // eax
  int v24; // eax
  int v25; // r9d
  int m_size; // ebp
  int v27; // r9d
  int v28; // eax
  int v29; // eax
  int v30; // r9d
  int v31; // edx
  float *v32; // rdi
  __int64 v33; // rcx
  char v34; // al
  hkResult v35; // [rsp+30h] [rbp-78h] BYREF
  hkResult v36; // [rsp+34h] [rbp-74h] BYREF
  hkResult v37; // [rsp+38h] [rbp-70h] BYREF
  hkResult v38; // [rsp+3Ch] [rbp-6Ch] BYREF
  hkResult v39; // [rsp+40h] [rbp-68h] BYREF
  __int64 v40; // [rsp+48h] [rbp-60h]
  __int64 v41; // [rsp+50h] [rbp-58h]
  UFG::RigHandle *result; // [rsp+B8h] [rbp+10h] BYREF
  hkResult v43; // [rsp+C0h] [rbp+18h] BYREF
  hkResult v44; // [rsp+C8h] [rbp+20h] BYREF

  v40 = -2i64;
  this->mRootTransformNode.mPrev = &this->mRootTransformNode;
  this->mRootTransformNode.mNext = &this->mRootTransformNode;
  this->mRootTransformNode.m_pPointer = 0i64;
  p_mRigHandle = &this->mRigHandle;
  result = &this->mRigHandle;
  UFG::qResourceHandle::qResourceHandle(&this->mRigHandle);
  p_mRigHandle->mLoadFunction = 0i64;
  p_mRigHandle->mUnloadFunction = 0i64;
  p_mRigHandle->mUserData = 0i64;
  p_mRigHandle->mUFGSkeleton = 0i64;
  v5 = 0i64;
  this->mRootQsMatrix.m_translation = 0i64;
  this->mRootQsMatrix.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  this->mRootQsMatrix.m_scale = (hkVector4f)query.m_quad;
  v5.x = (float)1;
  this->mRootMatrix44.v0 = v5;
  this->mRootMatrix44.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v5, (__m128)v5, 81);
  this->mRootMatrix44.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v5, (__m128)v5, 69);
  this->mRootMatrix44.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v5, (__m128)v5, 21);
  this->mIsRootDirty = 0;
  this->mCachedTransformChangeID = -1;
  mUID = rig->mNode.mUID;
  inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    inventory = UFG::qResourceWarehouse::GetInventory(v8, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = inventory;
  }
  UFG::qResourceHandle::Init(p_mRigHandle, 0x39BC0A7Eu, mUID, rig, inventory);
  this->mRigHandle.mUnloadFunction = SkeletalPose::RigUnloadedCallback;
  this->mRigHandle.mLoadFunction = SkeletalPose::RigLoadedCallback;
  this->mRigHandle.mUserData = this;
  v9 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v10 = ++*(_BYTE *)(v9 + 80);
  *(_DWORD *)(v9 + 4i64 * v10) = 2;
  *(_QWORD *)(v9 + 8i64 * v10 + 16) = "hkaPose";
  *(_QWORD *)(v9 + 8i64 * v10 + 48) = 0i64;
  v11 = *(_BYTE *)(v9 + 81);
  if ( v10 > v11 )
    v11 = v10;
  *(_BYTE *)(v9 + 81) = v11;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  v14 = (hkaPose *)v13;
  v41 = v13;
  if ( v13 )
  {
    *(_QWORD *)v13 = rig->mUFGSkeleton->mhkaSkeleton;
    *(_QWORD *)(v13 + 8) = 0i64;
    *(_DWORD *)(v13 + 16) = 0;
    *(_DWORD *)(v13 + 20) = 0x80000000;
    *(_QWORD *)(v13 + 24) = 0i64;
    *(_DWORD *)(v13 + 32) = 0;
    *(_DWORD *)(v13 + 36) = 0x80000000;
    *(_QWORD *)(v13 + 40) = 0i64;
    *(_DWORD *)(v13 + 48) = 0;
    *(_DWORD *)(v13 + 52) = 0x80000000;
    *(_WORD *)(v13 + 56) = 0;
    *(_QWORD *)(v13 + 64) = 0i64;
    *(_DWORD *)(v13 + 72) = 0;
    *(_DWORD *)(v13 + 76) = 0x80000000;
    v15 = *(_DWORD *)(*(_QWORD *)v13 + 48i64);
    v16 = (v15 + 3) & 0xFFFFFFFC;
    if ( (*(_DWORD *)(v13 + 36) & 0x3FFFFFFF) >= v16 )
      LODWORD(result) = 0;
    else
      hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, (void *)(v13 + 24), v16, 48);
    if ( (v14->m_localPose.m_capacityAndFlags & 0x3FFFFFFF) >= v16 )
      v43.m_enum = HK_SUCCESS;
    else
      hkArrayUtil::_reserve(&v43, &hkContainerHeapAllocator::s_alloc, &v14->m_localPose, v16, 48);
    if ( (v14->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) >= v16 )
      v44.m_enum = HK_SUCCESS;
    else
      hkArrayUtil::_reserve(&v44, &hkContainerHeapAllocator::s_alloc, &v14->m_boneFlags, v16, 4);
    v17 = v14->m_modelPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v17 >= v15 )
    {
      v35.m_enum = HK_SUCCESS;
    }
    else
    {
      v18 = 2 * v17;
      v19 = v15;
      if ( v15 < v18 )
        v19 = v18;
      hkArrayUtil::_reserve(&v35, &hkContainerHeapAllocator::s_alloc, &v14->m_modelPose, v19, 48);
    }
    v14->m_modelPose.m_size = v15;
    v20 = v14->m_localPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v20 >= v15 )
    {
      v36.m_enum = HK_SUCCESS;
    }
    else
    {
      v21 = 2 * v20;
      v22 = v15;
      if ( v15 < v21 )
        v22 = v21;
      hkArrayUtil::_reserve(&v36, &hkContainerHeapAllocator::s_alloc, &v14->m_localPose, v22, 48);
    }
    v14->m_localPose.m_size = v15;
    v23 = v14->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v23 >= v15 )
    {
      v37.m_enum = HK_SUCCESS;
    }
    else
    {
      v24 = 2 * v23;
      v25 = v15;
      if ( v15 < v24 )
        v25 = v24;
      hkArrayUtil::_reserve(&v37, &hkContainerHeapAllocator::s_alloc, &v14->m_boneFlags, v25, 4);
    }
    v14->m_boneFlags.m_size = v15;
    m_size = v14->m_skeleton->m_floatSlots.m_size;
    v27 = (m_size + 3) & 0xFFFFFFFC;
    if ( (v14->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) >= v27 )
      v38.m_enum = HK_SUCCESS;
    else
      hkArrayUtil::_reserve(&v38, &hkContainerHeapAllocator::s_alloc, &v14->m_floatSlotValues, v27, 4);
    v28 = v14->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v28 >= m_size )
    {
      v39.m_enum = HK_SUCCESS;
    }
    else
    {
      v29 = 2 * v28;
      v30 = m_size;
      if ( m_size < v29 )
        v30 = v29;
      hkArrayUtil::_reserve(&v39, &hkContainerHeapAllocator::s_alloc, &v14->m_floatSlotValues, v30, 4);
    }
    v31 = m_size - v14->m_floatSlotValues.m_size;
    v32 = &v14->m_floatSlotValues.m_data[v14->m_floatSlotValues.m_size];
    v33 = v31;
    if ( v31 > 0 )
    {
      while ( v33 )
      {
        *v32++ = 0.0;
        --v33;
      }
    }
    v14->m_floatSlotValues.m_size = m_size;
  }
  else
  {
    v14 = 0i64;
  }
  this->mHavokPose = v14;
  v34 = *(_BYTE *)(v9 + 80);
  if ( v34 > 0 )
  {
    *(_BYTE *)(v9 + 80) = v34 - 1;
  }
  else
  {
    *(_BYTE *)(v9 + 80) = 0;
    *(_DWORD *)v9 = 3;
    *(_QWORD *)(v9 + 16) = 0i64;
    *(_QWORD *)(v9 + 48) = 0i64;
  }
  this->mBoneUpdateCount = -1;
}

// File Line: 117
// RVA: 0x1BA190
void __fastcall SkeletalPose::~SkeletalPose(SkeletalPose *this)
{
  hkaPose *mHavokPose; // rdi
  _QWORD **Value; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mRootTransformNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  this->mRigHandle.mLoadFunction = 0i64;
  this->mRigHandle.mUnloadFunction = 0i64;
  this->mRigHandle.mUserData = 0i64;
  mHavokPose = this->mHavokPose;
  if ( mHavokPose )
  {
    hkaPose::~hkaPose(this->mHavokPose);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkaPose *, __int64))(*Value[11] + 16i64))(Value[11], mHavokPose, 80i64);
    this->mHavokPose = 0i64;
  }
  Inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mRigHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mRigHandle);
  p_mRootTransformNode = &this->mRootTransformNode;
  if ( this->mRootTransformNode.m_pPointer )
  {
    mPrev = p_mRootTransformNode->mPrev;
    mNext = this->mRootTransformNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mRootTransformNode->mPrev = p_mRootTransformNode;
    this->mRootTransformNode.mNext = &this->mRootTransformNode;
  }
  this->mRootTransformNode.m_pPointer = 0i64;
  v9 = p_mRootTransformNode->mPrev;
  v10 = this->mRootTransformNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mRootTransformNode->mPrev = p_mRootTransformNode;
  this->mRootTransformNode.mNext = &this->mRootTransformNode;
}

// File Line: 130
// RVA: 0x1BAB70
SkeletalPose *__fastcall SkeletalPose::Clone(SkeletalPose *this)
{
  __int64 v2; // rbx
  char v3; // dl
  char v4; // cl
  UFG::allocator::free_link *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rdi
  char v8; // al
  UFG::qVector4 v9; // xmm3
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1

  v2 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v3 = ++*(_BYTE *)(v2 + 80);
  *(_DWORD *)(v2 + 4i64 * v3) = 2;
  *(_QWORD *)(v2 + 8i64 * v3 + 16) = "SkeletalPose";
  *(_QWORD *)(v2 + 8i64 * v3 + 48) = 0i64;
  v4 = *(_BYTE *)(v2 + 81);
  if ( v3 > v4 )
    v4 = v3;
  *(_BYTE *)(v2 + 81) = v4;
  v5 = UFG::qMalloc(0x100ui64, "SkeletalPose.Clone", 0i64);
  if ( v5 )
  {
    SkeletalPose::SkeletalPose((SkeletalPose *)v5, this->mRigHandle.mNameUID);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = *(_BYTE *)(v2 + 80);
  if ( v8 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v8 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  SkeletalPose::syncTransformToRoot(this);
  v9 = this->mRootMatrix44.v1;
  v10 = this->mRootMatrix44.v2;
  v11 = this->mRootMatrix44.v3;
  *(UFG::qVector4 *)(v7 + 16) = this->mRootMatrix44.v0;
  *(UFG::qVector4 *)(v7 + 32) = v9;
  *(UFG::qVector4 *)(v7 + 48) = v10;
  *(UFG::qVector4 *)(v7 + 64) = v11;
  *(hkVector4f *)(v7 + 80) = this->mRootQsMatrix.m_translation;
  *(hkQuaternionf *)(v7 + 96) = this->mRootQsMatrix.m_rotation;
  *(hkVector4f *)(v7 + 112) = this->mRootQsMatrix.m_scale;
  *(_DWORD *)(v7 + 128) = this->mIsRootDirty;
  *(_DWORD *)(v7 + 132) = this->mCachedTransformChangeID;
  *(_DWORD *)v7 = this->mBoneUpdateCount;
  return (SkeletalPose *)v7;
}

// File Line: 178
// RVA: 0x1BE3F0
void __fastcall SkeletalPose::SetToRestPose(SkeletalPose *this)
{
  hkaPose *mHavokPose; // rcx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v3; // rax
  unsigned int m_size; // ecx
  __int64 v5; // rdx
  __int64 v6; // r8
  hkQsTransformf *m_data; // rcx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4

  hkaPose::setToReferencePose(this->mHavokPose);
  mHavokPose = this->mHavokPose;
  this->mPoseAABBMin.x = 3.4028235e38;
  this->mPoseAABBMin.y = 3.4028235e38;
  this->mPoseAABBMin.z = 3.4028235e38;
  this->mPoseAABBMax.x = -3.4028235e38;
  this->mPoseAABBMax.y = -3.4028235e38;
  this->mPoseAABBMax.z = -3.4028235e38;
  v3 = hkaPose::accessSyncedPoseModelSpace(mHavokPose);
  m_size = v3->m_size;
  if ( m_size > 1 )
  {
    v5 = 1i64;
    v6 = m_size - 1;
    do
    {
      m_data = v3->m_data;
      x = this->mPoseAABBMin.x;
      if ( x >= v3->m_data[v5].m_translation.m_quad.m128_f32[0] )
        x = v3->m_data[v5].m_translation.m_quad.m128_f32[0];
      this->mPoseAABBMin.x = x;
      y = this->mPoseAABBMin.y;
      if ( y >= m_data[v5].m_translation.m_quad.m128_f32[1] )
        y = m_data[v5].m_translation.m_quad.m128_f32[1];
      this->mPoseAABBMin.y = y;
      z = this->mPoseAABBMin.z;
      if ( z >= m_data[v5].m_translation.m_quad.m128_f32[2] )
        z = m_data[v5].m_translation.m_quad.m128_f32[2];
      this->mPoseAABBMin.z = z;
      v11 = this->mPoseAABBMax.x;
      if ( v11 <= m_data[v5].m_translation.m_quad.m128_f32[0] )
        v11 = m_data[v5].m_translation.m_quad.m128_f32[0];
      this->mPoseAABBMax.x = v11;
      v12 = this->mPoseAABBMax.y;
      if ( v12 <= m_data[v5].m_translation.m_quad.m128_f32[1] )
        v12 = m_data[v5].m_translation.m_quad.m128_f32[1];
      this->mPoseAABBMax.y = v12;
      v13 = this->mPoseAABBMax.z;
      if ( v13 <= m_data[v5].m_translation.m_quad.m128_f32[2] )
        v13 = m_data[v5].m_translation.m_quad.m128_f32[2];
      ++v5;
      this->mPoseAABBMax.z = v13;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 213
// RVA: 0x1BBF50
void __fastcall SkeletalPose::Renormalize(SkeletalPose *this, bool syncedPose, bool skipScaleable)
{
  hkaPose *mHavokPose; // r9
  int m_size; // edi
  hkaSkeleton *m_skeleton; // r13
  __int64 v8; // r14
  hkLifoAllocator *Value; // rax
  int v10; // edx
  float *m_cur; // rcx
  char *v12; // r8
  int v13; // r9d
  float *v14; // rbx
  unsigned int v15; // esi
  hkQsTransformf *v16; // rax
  hkVector4f v17; // xmm5
  __m128 m_quad; // xmm4
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  hkaPose *v23; // rcx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v24; // rax
  char *v25; // rdi
  int v26; // ecx
  int v27; // ebx
  hkLifoAllocator *v28; // rax
  signed int v29; // ebx
  int v30; // r8d
  float *array; // [rsp+38h] [rbp-28h] BYREF
  int v32; // [rsp+40h] [rbp-20h]
  int v33; // [rsp+44h] [rbp-1Ch]
  void *p; // [rsp+48h] [rbp-18h]
  int v35; // [rsp+50h] [rbp-10h]
  float *result; // [rsp+A0h] [rbp+40h] BYREF
  bool v37; // [rsp+A8h] [rbp+48h]

  v37 = syncedPose;
  mHavokPose = this->mHavokPose;
  m_size = mHavokPose->m_skeleton->m_bones.m_size;
  m_skeleton = mHavokPose->m_skeleton;
  v8 = 0i64;
  array = 0i64;
  v32 = 0;
  v33 = 0x80000000;
  v35 = m_size;
  if ( m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (((4 * m_size + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    m_cur = (float *)Value->m_cur;
    v12 = (char *)m_cur + v10;
    if ( v10 > Value->m_slabSize || v12 > Value->m_end )
      m_cur = (float *)hkLifoAllocator::allocateFromNewSlab(Value, v10);
    else
      Value->m_cur = v12;
  }
  else
  {
    m_cur = 0i64;
  }
  array = m_cur;
  v33 = m_size | 0x80000000;
  p = m_cur;
  if ( (m_size & 0x3FFFFFFF) < m_size )
  {
    v13 = m_size;
    if ( m_size < 2 * (m_size & 0x3FFFFFFF) )
      v13 = 2 * (m_size & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, &array, v13, 4);
  }
  v32 = m_size;
  v14 = array;
  result = array;
  v15 = 0;
  if ( m_size )
  {
    do
    {
      if ( !skipScaleable || m_skeleton->m_bones.m_data[v8].m_lockTranslation.m_bool )
      {
        *v14 = 1.0;
      }
      else
      {
        *v14 = 0.0;
        v16 = hkaPose::accessBoneLocalSpace(this->mHavokPose, v15);
        v17.m_quad = (__m128)v16->m_scale;
        m_quad = v16->m_rotation.m_vec.m_quad;
        v19 = _mm_mul_ps(m_quad, m_quad);
        v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 78), v19);
        v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20);
        v22 = _mm_rsqrt_ps(v21);
        v16->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                         _mm_mul_ps(
                                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                                           _mm_mul_ps(*(__m128 *)_xmm, v22)),
                                         m_quad);
        v16->m_scale = (hkVector4f)v17.m_quad;
      }
      ++v15;
      ++v8;
      ++v14;
    }
    while ( v15 < m_size );
    v14 = result;
  }
  v23 = this->mHavokPose;
  if ( v37 )
    v24 = hkaPose::accessSyncedPoseLocalSpace(v23);
  else
    v24 = hkaPose::accessUnsyncedPoseLocalSpace(v23);
  hkQsTransformf::fastRenormalizeBatch(v24->m_data, v14, m_size);
  v25 = (char *)p;
  v26 = v32;
  if ( p == array )
    v26 = 0;
  v32 = v26;
  v27 = v35;
  v28 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v29 = (4 * v27 + 127) & 0xFFFFFF80;
  v30 = (v29 + 15) & 0xFFFFFFF0;
  if ( v29 > v28->m_slabSize || &v25[v30] != v28->m_cur || v28->m_firstNonLifoEnd == v25 )
    hkLifoAllocator::slowBlockFree(v28, v25, v30);
  else
    v28->m_cur = v25;
  v32 = 0;
  if ( v33 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v33);
}

// File Line: 293
// RVA: 0x1BE540
void __fastcall UFG::EncounterUnitComponent::SetGroupVehicle(
        SkeletalPose *this,
        UFG::TransformNodeComponent *transformNodeRoot)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mRootTransformNode; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  p_mRootTransformNode = &this->mRootTransformNode;
  if ( this->mRootTransformNode.m_pPointer )
  {
    mPrev = p_mRootTransformNode->mPrev;
    mNext = p_mRootTransformNode->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mRootTransformNode->mPrev = p_mRootTransformNode;
    p_mRootTransformNode->mNext = p_mRootTransformNode;
  }
  p_mRootTransformNode->m_pPointer = transformNodeRoot;
  if ( transformNodeRoot )
  {
    v5 = transformNodeRoot->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v5->mNext = p_mRootTransformNode;
    p_mRootTransformNode->mPrev = v5;
    p_mRootTransformNode->mNext = &transformNodeRoot->m_SafePointerList.mNode;
    transformNodeRoot->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mRootTransformNode;
  }
}

// File Line: 304
// RVA: 0x1BE8F0
void __fastcall SkeletalPose::syncTransformToRoot(SkeletalPose *this)
{
  UFG::SimComponent *m_pPointer; // rdi
  unsigned int v3; // esi
  UFG::qVector4 v4; // xmm3
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 m_BoundComponentHandles; // xmm1

  m_pPointer = this->mRootTransformNode.m_pPointer;
  if ( m_pPointer )
  {
    v3 = *(_DWORD *)&m_pPointer[1].m_Flags;
    if ( !sCheckCachedChangeID || this->mCachedTransformChangeID != v3 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
      v4 = *(UFG::qVector4 *)&m_pPointer[2].m_SafePointerList.mNode.mNext;
      v5 = *(UFG::qVector4 *)&m_pPointer[2].m_Flags;
      m_BoundComponentHandles = (UFG::qVector4)m_pPointer[2].m_BoundComponentHandles;
      this->mRootMatrix44.v0 = *(UFG::qVector4 *)&m_pPointer[2].vfptr;
      this->mRootMatrix44.v1 = v4;
      this->mRootMatrix44.v2 = v5;
      this->mRootMatrix44.v3 = m_BoundComponentHandles;
      this->mIsRootDirty = 1;
      this->mCachedTransformChangeID = v3;
    }
  }
}

// File Line: 320
// RVA: 0x1BBED0
bool __fastcall SkeletalPose::HasPoseChanged(SkeletalPose *this)
{
  UFG::SimComponent *m_pPointer; // rdx

  m_pPointer = this->mRootTransformNode.m_pPointer;
  return m_pPointer && *(_DWORD *)&m_pPointer[1].m_Flags != this->mCachedTransformChangeID;
}

// File Line: 342
// RVA: 0x1BE2F0
void __fastcall SkeletalPose::SetRoot(SkeletalPose *this, UFG::qMatrix44 *newRoot, bool forceTeleportEvent)
{
  UFG::qVector4 v3; // xmm3
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v7; // xmm1
  UFG::TransformNodeComponent *m_pPointer; // rcx

  v3 = newRoot->v1;
  v4 = newRoot->v2;
  v7 = newRoot->v3;
  this->mRootMatrix44.v0 = newRoot->v0;
  this->mRootMatrix44.v1 = v3;
  this->mRootMatrix44.v2 = v4;
  this->mRootMatrix44.v3 = v7;
  this->mIsRootDirty = 1;
  m_pPointer = (UFG::TransformNodeComponent *)this->mRootTransformNode.m_pPointer;
  if ( m_pPointer )
    UFG::TransformNodeComponent::SetWorldTransform(m_pPointer, newRoot);
  if ( forceTeleportEvent )
    SkeletalPose::forceTeleport(this);
}

// File Line: 356
// RVA: 0x1BE270
void __fastcall SkeletalPose::SetRoot(SkeletalPose *this, hkQsTransformf *newRoot, bool forceTeleportEvent)
{
  UFG::TransformNodeComponent *m_pPointer; // rcx

  this->mRootQsMatrix = *newRoot;
  hkQsTransformf::get4x4ColumnMajor(newRoot, &this->mRootMatrix44.v0.x);
  m_pPointer = (UFG::TransformNodeComponent *)this->mRootTransformNode.m_pPointer;
  this->mIsRootDirty = 0;
  if ( m_pPointer )
    UFG::TransformNodeComponent::SetWorldTransform(m_pPointer, &this->mRootMatrix44);
  if ( forceTeleportEvent )
    SkeletalPose::forceTeleport(this);
}

// File Line: 366
// RVA: 0x1BE360
void __fastcall SkeletalPose::SetRootTranslation(SkeletalPose *this, UFG::qVector3 *trans, bool forceTeleportEvent)
{
  float x; // eax
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::TransformNodeComponent *m_pPointer; // rcx

  x = trans->x;
  y = trans->y;
  z = trans->z;
  this->mRootMatrix44.v3.w = 1.0;
  this->mRootMatrix44.v3.x = x;
  this->mRootMatrix44.v3.y = y;
  this->mRootMatrix44.v3.z = z;
  if ( !this->mIsRootDirty )
    this->mRootQsMatrix.m_translation.m_quad = _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps((__m128)LODWORD(trans->x), (__m128)LODWORD(trans->z)),
                                                 _mm_unpacklo_ps(
                                                   (__m128)LODWORD(trans->y),
                                                   (__m128)(unsigned int)FLOAT_1_0));
  m_pPointer = (UFG::TransformNodeComponent *)this->mRootTransformNode.m_pPointer;
  if ( m_pPointer )
    UFG::TransformNodeComponent::SetWorldTransform(m_pPointer, &this->mRootMatrix44);
  if ( forceTeleportEvent )
    SkeletalPose::forceTeleport(this);
}

// File Line: 376
// RVA: 0x1BE810
void __fastcall SkeletalPose::forceTeleport(SkeletalPose *this)
{
  UFG::SimComponent *m_pPointer; // rax
  UFG::SimObject *m_pSimObject; // rdi
  UFG::allocator::free_link *v4; // rax
  UFG::TeleportEvent *v5; // rbp
  unsigned int mUID; // esi
  UFG::SimComponent *v7; // rdi
  UFG::SimComponent *v8; // rbx

  m_pPointer = this->mRootTransformNode.m_pPointer;
  if ( m_pPointer )
  {
    m_pSimObject = m_pPointer->m_pSimObject;
    v4 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
    v5 = (UFG::TeleportEvent *)v4;
    if ( v4 )
    {
      mUID = m_pSimObject->mNode.mUID;
      v7 = this->mRootTransformNode.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
      v8 = this->mRootTransformNode.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v8);
      UFG::TeleportEvent::TeleportEvent(
        v5,
        (UFG::qVector3 *)&v8[2].m_BoundComponentHandles,
        (UFG::qVector3 *)&v7[2],
        mUID,
        0,
        UFG::TeleportEvent::m_Name,
        &UFG::qVector3::msDirUp);
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v4);
  }
}

// File Line: 387
// RVA: 0x1BBD80
hkQsTransformf *__fastcall SkeletalPose::GetRoot(SkeletalPose *this)
{
  hkTransformf transform; // [rsp+20h] [rbp-48h] BYREF

  SkeletalPose::syncTransformToRoot(this);
  if ( this->mIsRootDirty )
  {
    hkTransformf::set4x4ColumnMajor(&transform, &this->mRootMatrix44.v0.x);
    hkQsTransformf::setFromTransformNoScale(&this->mRootQsMatrix, &transform);
    this->mIsRootDirty = 0;
  }
  return &this->mRootQsMatrix;
}

// File Line: 393
// RVA: 0x1BBDD0
void __fastcall SkeletalPose::GetRootMatrix(SkeletalPose *this, UFG::qMatrix44 *matrixRoot)
{
  UFG::qVector4 v4; // xmm3
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm1

  SkeletalPose::syncTransformToRoot(this);
  v4 = this->mRootMatrix44.v1;
  v5 = this->mRootMatrix44.v2;
  v6 = this->mRootMatrix44.v3;
  matrixRoot->v0 = this->mRootMatrix44.v0;
  matrixRoot->v1 = v4;
  matrixRoot->v2 = v5;
  matrixRoot->v3 = v6;
}

// File Line: 399
// RVA: 0x1BBB90
void __fastcall SkeletalPose::GetPositionWS(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixWS)
{
  __int64 v4; // rbx
  hkQsTransformf *v6; // r9
  __m128 m_quad; // xmm7
  __m128 v8; // xmm6
  __m128 v9; // xmm8
  hkQuaternionf v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm5
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm6
  __m128 v19; // xmm2
  hkVector4f v20; // xmm0
  hkQsTransformf v21; // [rsp+20h] [rbp-A8h] BYREF
  hkTransformf transform; // [rsp+50h] [rbp-78h] BYREF

  v4 = boneID;
  SkeletalPose::syncTransformToRoot(this);
  v6 = &hkaPose::getSyncedPoseModelSpace(this->mHavokPose)->m_data[v4];
  m_quad = v6->m_translation.m_quad;
  v8 = v6->m_rotation.m_vec.m_quad;
  v9 = v6->m_scale.m_quad;
  if ( this->mIsRootDirty )
  {
    hkTransformf::set4x4ColumnMajor(&transform, &this->mRootMatrix44.v0.x);
    hkQsTransformf::setFromTransformNoScale(&this->mRootQsMatrix, &transform);
    this->mIsRootDirty = 0;
  }
  v10.m_vec.m_quad = (__m128)this->mRootQsMatrix.m_rotation;
  v11 = _mm_mul_ps(v10.m_vec.m_quad, m_quad);
  v12 = _mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 255);
  v13 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v10.m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 201), m_quad));
  v14 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                _mm_shuffle_ps(v11, v11, 170)),
              v10.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v12));
  v15 = _mm_shuffle_ps(v8, v8, 255);
  v21.m_translation.m_quad = _mm_add_ps(_mm_add_ps(v14, v14), this->mRootQsMatrix.m_translation.m_quad);
  v16 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v10.m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 201), v8));
  v17 = v8;
  v18 = _mm_mul_ps(v8, v10.m_vec.m_quad);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 201), _mm_mul_ps(v17, v12)), _mm_mul_ps(v15, v10.m_vec.m_quad));
  v20.m_quad = _mm_mul_ps(this->mRootQsMatrix.m_scale.m_quad, v9);
  v21.m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                  v19,
                                  _mm_unpackhi_ps(
                                    v19,
                                    _mm_sub_ps(
                                      _mm_mul_ps(v15, v12),
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                                        _mm_shuffle_ps(v18, v18, 170)))),
                                  196);
  v21.m_scale = (hkVector4f)v20.m_quad;
  hkQsTransformf::get4x4ColumnMajor(&v21, &matrixWS->v0.x);
}

// File Line: 415
// RVA: 0x1BBE10
void __fastcall SkeletalPose::GetTranslationWS(SkeletalPose *this, int boneID, UFG::qVector3 *translationWS)
{
  __int64 v4; // rbx
  hkaPose *mHavokPose; // r9
  hkQsTransformf *v7; // rbx
  float v8; // xmm1_4
  float v9; // xmm0_4
  hkVector4f v10; // [rsp+20h] [rbp-58h] BYREF
  hkTransformf transform; // [rsp+30h] [rbp-48h] BYREF

  v4 = boneID;
  SkeletalPose::syncTransformToRoot(this);
  mHavokPose = this->mHavokPose;
  if ( (mHavokPose->m_boneFlags.m_data[v4] & 2) != 0 )
    v7 = hkaPose::calculateBoneModelSpace(this->mHavokPose, v4);
  else
    v7 = &mHavokPose->m_modelPose.m_data[v4];
  if ( this->mIsRootDirty )
  {
    hkTransformf::set4x4ColumnMajor(&transform, &this->mRootMatrix44.v0.x);
    hkQsTransformf::setFromTransformNoScale(&this->mRootQsMatrix, &transform);
    this->mIsRootDirty = 0;
  }
  hkVector4f::setTransformedPos(&v10, &this->mRootQsMatrix, &v7->m_translation);
  v8 = v10.m_quad.m128_f32[1];
  LODWORD(translationWS->x) = v10.m_quad.m128_i32[0];
  v9 = v10.m_quad.m128_f32[2];
  translationWS->y = v8;
  translationWS->z = v9;
}

// File Line: 448
// RVA: 0x1BD0C0
void __fastcall SkeletalPose::SetPositionWS(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixWS)
{
  __int64 v4; // rbp
  __m128i inserted; // xmm0
  __m128 v7; // xmm13
  __m128 v8; // xmm14
  __m128 v9; // xmm7
  hkVector4f v10; // xmm0
  __m128 v11; // xmm1
  __m128 v12; // xmm6
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128i v15; // xmm8
  __m128 v16; // xmm1
  __m128 v17; // xmm10
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm10
  __m128 v21; // xmm11
  __m128 v22; // xmm11
  hkaPose *mHavokPose; // rsi
  __int64 v24; // r8
  __m128 v25; // xmm11
  __m128 v26; // xmm12
  __int64 m_size; // rcx
  int v28; // eax
  __int64 v29; // r13
  __int64 v30; // r14
  __int64 v31; // rbp
  __int64 v32; // rdx
  unsigned int *m_data; // rcx
  hkQsTransformf *v34; // r12
  hkQsTransformf *v35; // r15
  hkQsTransformf *v36; // rdi
  __m128 m_quad; // xmm3
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  __m128 v40; // xmm8
  __m128 v41; // xmm7
  __m128 v42; // xmm9
  __m128 v43; // xmm1
  __m128 v44; // xmm5
  __m128 v45; // xmm4
  __m128 v46; // xmm2
  __m128 v47; // xmm2
  __m128 v48; // xmm3
  __m128 v49; // xmm4
  __m128 v50; // xmm1
  __m128 v51; // xmm8
  __m128 v52; // xmm4
  __m128 v53; // xmm4
  __int64 i; // rcx
  unsigned int *v55; // rdx
  unsigned int v56; // eax
  __m128 *p_m_quad; // rax
  hkVector4f v58; // [rsp+20h] [rbp-178h] BYREF
  __m128 v59; // [rsp+30h] [rbp-168h]
  __m128 v60; // [rsp+40h] [rbp-158h]
  hkTransformf transform; // [rsp+50h] [rbp-148h] BYREF
  hkQsTransformf v62; // [rsp+90h] [rbp-108h] BYREF
  int v63; // [rsp+1A8h] [rbp+10h]
  __int64 v64; // [rsp+1B8h] [rbp+20h]

  if ( boneID >= 0 )
  {
    v4 = boneID;
    SkeletalPose::syncTransformToRoot(this);
    hkTransformf::set4x4ColumnMajor(&transform, &matrixWS->v0.x);
    hkQsTransformf::setFromTransformNoScale(&v62, &transform);
    if ( this->mIsRootDirty )
    {
      hkTransformf::set4x4ColumnMajor(&transform, &this->mRootMatrix44.v0.x);
      hkQsTransformf::setFromTransformNoScale(&this->mRootQsMatrix, &transform);
      this->mIsRootDirty = 0;
    }
    hkVector4f::setRotatedInverseDir(&v58, &this->mRootQsMatrix.m_rotation, &this->mRootQsMatrix.m_translation);
    inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    v7 = (__m128)_mm_shuffle_epi32(inserted, 0);
    v8 = (__m128)_mm_shuffle_epi32(inserted, 64);
    v9 = _mm_xor_ps(this->mRootQsMatrix.m_rotation.m_vec.m_quad, v8);
    v10.m_quad = (__m128)this->mRootQsMatrix.m_scale;
    v11 = _mm_rcp_ps(v10.m_quad);
    v58.m_quad = _mm_xor_ps(v58.m_quad, v7);
    v59 = v9;
    v12 = _mm_shuffle_ps(v9, v9, 255);
    v13 = _mm_shuffle_ps(v9, v9, 201);
    v14 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v62.m_translation.m_quad, v62.m_translation.m_quad, 201), v9),
            _mm_mul_ps(v13, v62.m_translation.m_quad));
    v15 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10.m_quad, v11)), v11), 4);
    v16 = _mm_mul_ps(v62.m_translation.m_quad, v9);
    v60 = (__m128)_mm_srli_si128(v15, 4);
    v17 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                  _mm_shuffle_ps(v16, v16, 170)),
                v9),
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), v62.m_translation.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v12));
    v18 = _mm_shuffle_ps(v62.m_rotation.m_vec.m_quad, v62.m_rotation.m_vec.m_quad, 255);
    v19 = _mm_mul_ps(v62.m_rotation.m_vec.m_quad, v9);
    v20 = _mm_add_ps(_mm_add_ps(v17, v17), v58.m_quad);
    v21 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v62.m_rotation.m_vec.m_quad, v62.m_rotation.m_vec.m_quad, 201), v9),
            _mm_mul_ps(v13, v62.m_rotation.m_vec.m_quad));
    v22 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v21, v21, 201), _mm_mul_ps(v62.m_rotation.m_vec.m_quad, v12)),
            _mm_mul_ps(v9, v18));
    mHavokPose = this->mHavokPose;
    v24 = v4;
    v64 = v4;
    v25 = _mm_shuffle_ps(
            v22,
            _mm_unpackhi_ps(
              v22,
              _mm_sub_ps(
                _mm_mul_ps(v18, v12),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                  _mm_shuffle_ps(v19, v19, 170)))),
            196);
    v26 = _mm_mul_ps(v62.m_scale.m_quad, v60);
    m_size = mHavokPose->m_skeleton->m_bones.m_size;
    mHavokPose->m_boneFlags.m_data[v4] |= 4u;
    v28 = v4 + 1;
    v29 = m_size;
    v30 = (int)v4 + 1;
    v63 = v4 + 1;
    if ( v30 < m_size )
    {
      v31 = v28;
      do
      {
        LOWORD(v32) = mHavokPose->m_skeleton->m_parentIndices.m_data[v30];
        if ( (_WORD)v32 != 0xFFFF )
        {
          m_data = mHavokPose->m_boneFlags.m_data;
          if ( (m_data[(__int16)v32] & 4) != 0 )
          {
            if ( (m_data[v30] & 1) != 0 )
            {
              v34 = mHavokPose->m_modelPose.m_data;
              v32 = (__int16)v32;
              if ( (m_data[(__int16)v32] & 2) != 0 )
                v35 = hkaPose::calculateBoneModelSpace(mHavokPose, v32);
              else
                v35 = &v34[v32];
              v36 = mHavokPose->m_localPose.m_data;
              hkVector4f::setRotatedInverseDir(&transform.m_rotation.m_col0, &v35->m_rotation, &v35->m_translation);
              m_quad = v34[v31].m_translation.m_quad;
              v38 = v35->m_scale.m_quad;
              v39 = _mm_rcp_ps(v38);
              v40 = _mm_xor_ps(v8, v35->m_rotation.m_vec.m_quad);
              v41 = _mm_shuffle_ps(v40, v40, 255);
              v42 = (__m128)_mm_srli_si128(
                              _mm_slli_si128(
                                (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v38, v39)), v39),
                                4),
                              4);
              v43 = _mm_mul_ps(v40, m_quad);
              v44 = _mm_shuffle_ps(v40, v40, 201);
              v45 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v40), _mm_mul_ps(m_quad, v44));
              v46 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                            _mm_shuffle_ps(v43, v43, 170)),
                          v40),
                        _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v41, v41), (__m128)xmmword_141A711B0), m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), v41));
              v36[v31].m_translation.m_quad = _mm_add_ps(
                                                _mm_add_ps(v46, v46),
                                                _mm_xor_ps(transform.m_rotation.m_col0.m_quad, v7));
              v47 = v34[v31].m_rotation.m_vec.m_quad;
              v48 = _mm_shuffle_ps(v47, v47, 255);
              v49 = _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v40);
              v50 = _mm_mul_ps(v40, v48);
              v51 = _mm_mul_ps(v40, v47);
              v52 = _mm_sub_ps(v49, _mm_mul_ps(v47, v44));
              v53 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v52, v52, 201), _mm_mul_ps(v41, v47)), v50);
              v36[v31].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                   v53,
                                                   _mm_unpackhi_ps(
                                                     v53,
                                                     _mm_sub_ps(
                                                       _mm_mul_ps(v48, v41),
                                                       _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_shuffle_ps(v51, v51, 85),
                                                           _mm_shuffle_ps(v51, v51, 0)),
                                                         _mm_shuffle_ps(v51, v51, 170)))),
                                                   196);
              v36[v31].m_scale.m_quad = _mm_mul_ps(v34[v31].m_scale.m_quad, v42);
              mHavokPose->m_boneFlags.m_data[v30] &= ~1u;
            }
            mHavokPose->m_boneFlags.m_data[v30] |= 4u;
            mHavokPose->m_modelInSync.m_bool = 0;
          }
        }
        ++v30;
        ++v31;
      }
      while ( v30 < v29 );
      v24 = v64;
      v28 = v63;
    }
    for ( i = v28; i < v29; ++i )
    {
      v55 = mHavokPose->m_boneFlags.m_data;
      v56 = v55[i];
      if ( (v56 & 4) != 0 )
        v55[i] = v56 & 0xFFFFFFF9 | 2;
    }
    p_m_quad = &mHavokPose->m_modelPose.m_data[v24].m_translation.m_quad;
    *p_m_quad = v20;
    p_m_quad[1] = v25;
    p_m_quad[2] = v26;
    mHavokPose->m_boneFlags.m_data[v24] = 1;
    mHavokPose->m_localInSync.m_bool = 0;
  }
}

// File Line: 472
// RVA: 0x1BD620
void __fastcall SkeletalPose::SetPositionWS(SkeletalPose *this, int *boneID, hkQsTransformf *xformWS, int count)
{
  __int64 v4; // rsi
  hkQsTransformf *v5; // r15
  int *v6; // r12
  SkeletalPose *v7; // r14
  __int64 v8; // rbp
  __int64 v9; // r9
  __m128i inserted; // xmm0
  __m128 v11; // xmm13
  __m128 v12; // xmm14
  __m128 m_quad; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm8
  __m128 v16; // xmm6
  __m128 v17; // xmm7
  hkaPose *mHavokPose; // rsi
  __int64 v19; // r8
  __m128 v20; // xmm4
  __m128 v21; // xmm12
  __m128 v22; // xmm1
  __m128 v23; // xmm5
  __int64 m_size; // r13
  __m128 v25; // xmm3
  __m128 v26; // xmm10
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm2
  int v30; // eax
  __int64 v31; // r14
  __m128 v32; // xmm10
  __m128 v33; // xmm11
  __m128 v34; // xmm6
  __m128 v35; // xmm3
  __m128 v36; // xmm10
  __m128 v37; // xmm11
  __m128 v38; // xmm11
  __m128 v39; // xmm11
  __int64 v40; // rbp
  __int16 v41; // dx
  unsigned int *m_data; // rcx
  hkQsTransformf *v43; // r12
  hkQsTransformf *v44; // r15
  hkQsTransformf *v45; // rdi
  __m128 v46; // xmm3
  __m128 v47; // xmm2
  __m128 v48; // xmm8
  __m128 v49; // xmm7
  __m128 v50; // xmm5
  __m128 v51; // xmm1
  __m128 v52; // xmm4
  __m128 v53; // xmm9
  __m128 v54; // xmm2
  __m128 v55; // xmm2
  __m128 v56; // xmm3
  __m128 v57; // xmm4
  __m128 v58; // xmm1
  __m128 v59; // xmm8
  __m128 v60; // xmm4
  __m128 v61; // xmm4
  __int64 i; // rcx
  unsigned int *v63; // rdx
  unsigned int v64; // eax
  __m128 *p_m_quad; // rax
  __int64 v66; // [rsp+20h] [rbp-178h]
  __int64 v67; // [rsp+28h] [rbp-170h]
  __int64 v68; // [rsp+30h] [rbp-168h]
  hkVector4f v69; // [rsp+40h] [rbp-158h] BYREF
  __m128 v70; // [rsp+50h] [rbp-148h]
  __m128 v71; // [rsp+60h] [rbp-138h]
  hkTransformf transform; // [rsp+70h] [rbp-128h] BYREF
  hkQsTransformf *v75; // [rsp+1B0h] [rbp+18h]
  int v76; // [rsp+1B8h] [rbp+20h]

  v75 = xformWS;
  v4 = count;
  v5 = xformWS;
  v6 = boneID;
  v7 = this;
  SkeletalPose::syncTransformToRoot(this);
  v8 = 0i64;
  v66 = 0i64;
  if ( v7->mIsRootDirty )
  {
    hkTransformf::set4x4ColumnMajor(&transform, &v7->mRootMatrix44.v0.x);
    hkQsTransformf::setFromTransformNoScale(&v7->mRootQsMatrix, &transform);
    v7->mIsRootDirty = 0;
  }
  hkVector4f::setRotatedInverseDir(&v69, &v7->mRootQsMatrix.m_rotation, &v7->mRootQsMatrix.m_translation);
  v9 = v4;
  inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v67 = v4;
  v11 = (__m128)_mm_shuffle_epi32(inserted, 0);
  v12 = (__m128)_mm_shuffle_epi32(inserted, 64);
  m_quad = v7->mRootQsMatrix.m_scale.m_quad;
  v14 = _mm_rcp_ps(m_quad);
  v15 = _mm_xor_ps(v69.m_quad, v11);
  v69.m_quad = v15;
  v16 = _mm_xor_ps(v12, v7->mRootQsMatrix.m_rotation.m_vec.m_quad);
  v70 = v16;
  v17 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(m_quad, v14)), v14), 4),
                  4);
  v71 = v17;
  if ( (int)v4 > 0 )
  {
    while ( 1 )
    {
      mHavokPose = v7->mHavokPose;
      v19 = v6[v8];
      v68 = v19;
      v20 = _mm_shuffle_ps(v16, v16, 201);
      v21 = _mm_mul_ps(v5->m_scale.m_quad, v17);
      v22 = _mm_mul_ps(v16, v5->m_translation.m_quad);
      v23 = _mm_shuffle_ps(v16, v16, 255);
      m_size = mHavokPose->m_skeleton->m_bones.m_size;
      v25 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v5->m_translation.m_quad, v5->m_translation.m_quad, 201), v16),
              _mm_mul_ps(v20, v5->m_translation.m_quad));
      v26 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170));
      v27 = v16;
      v28 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v23, v23), (__m128)xmmword_141A711B0), v5->m_translation.m_quad);
      v29 = v5->m_rotation.m_vec.m_quad;
      mHavokPose->m_boneFlags.m_data[v19] |= 4u;
      v30 = v19 + 1;
      v31 = (int)v19 + 1;
      v76 = v19 + 1;
      v32 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v26, v16), v28), _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v23));
      v33 = _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v16);
      v34 = _mm_mul_ps(v16, v29);
      v35 = _mm_shuffle_ps(v29, v29, 255);
      v36 = _mm_add_ps(_mm_add_ps(v32, v32), v15);
      v37 = _mm_sub_ps(v33, _mm_mul_ps(v20, v29));
      v38 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v37, v37, 201), _mm_mul_ps(v29, v23)), _mm_mul_ps(v27, v35));
      v39 = _mm_shuffle_ps(
              v38,
              _mm_unpackhi_ps(
                v38,
                _mm_sub_ps(
                  _mm_mul_ps(v35, v23),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                    _mm_shuffle_ps(v34, v34, 170)))),
              196);
      if ( v31 < m_size )
      {
        v40 = v30;
        do
        {
          v41 = mHavokPose->m_skeleton->m_parentIndices.m_data[v31];
          if ( v41 != -1 )
          {
            m_data = mHavokPose->m_boneFlags.m_data;
            if ( (m_data[v41] & 4) != 0 )
            {
              if ( (m_data[v31] & 1) != 0 )
              {
                v43 = mHavokPose->m_modelPose.m_data;
                if ( (m_data[v41] & 2) != 0 )
                  v44 = hkaPose::calculateBoneModelSpace(mHavokPose, v41);
                else
                  v44 = &v43[v41];
                v45 = mHavokPose->m_localPose.m_data;
                hkVector4f::setRotatedInverseDir(&transform.m_rotation.m_col0, &v44->m_rotation, &v44->m_translation);
                v46 = v43[v40].m_translation.m_quad;
                v47 = _mm_rcp_ps(v44->m_scale.m_quad);
                v48 = _mm_xor_ps(v44->m_rotation.m_vec.m_quad, v12);
                v49 = _mm_shuffle_ps(v48, v48, 255);
                v50 = _mm_shuffle_ps(v48, v48, 201);
                v51 = _mm_mul_ps(v48, v46);
                v52 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v48), _mm_mul_ps(v46, v50));
                v53 = (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v47, v44->m_scale.m_quad)),
                                             v47),
                                  4),
                                4);
                v54 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
                              _mm_shuffle_ps(v51, v51, 170)),
                            v48),
                          _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v49, v49), (__m128)xmmword_141A711B0), v46)),
                        _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v49));
                v45[v40].m_translation.m_quad = _mm_add_ps(
                                                  _mm_add_ps(v54, v54),
                                                  _mm_xor_ps(transform.m_rotation.m_col0.m_quad, v11));
                v55 = v43[v40].m_rotation.m_vec.m_quad;
                v56 = _mm_shuffle_ps(v55, v55, 255);
                v57 = _mm_mul_ps(_mm_shuffle_ps(v55, v55, 201), v48);
                v58 = _mm_mul_ps(v48, v56);
                v59 = _mm_mul_ps(v48, v55);
                v60 = _mm_sub_ps(v57, _mm_mul_ps(v55, v50));
                v61 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v60, v60, 201), _mm_mul_ps(v49, v55)), v58);
                v45[v40].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                     v61,
                                                     _mm_unpackhi_ps(
                                                       v61,
                                                       _mm_sub_ps(
                                                         _mm_mul_ps(v56, v49),
                                                         _mm_add_ps(
                                                           _mm_add_ps(
                                                             _mm_shuffle_ps(v59, v59, 85),
                                                             _mm_shuffle_ps(v59, v59, 0)),
                                                           _mm_shuffle_ps(v59, v59, 170)))),
                                                     196);
                v45[v40].m_scale.m_quad = _mm_mul_ps(v43[v40].m_scale.m_quad, v53);
                mHavokPose->m_boneFlags.m_data[v31] &= ~1u;
              }
              mHavokPose->m_boneFlags.m_data[v31] |= 4u;
              mHavokPose->m_modelInSync.m_bool = 0;
            }
          }
          ++v31;
          ++v40;
        }
        while ( v31 < m_size );
        v8 = v66;
        v19 = v68;
        v5 = v75;
        v30 = v76;
        v9 = v67;
        v6 = boneID;
      }
      for ( i = v30; i < m_size; ++i )
      {
        v63 = mHavokPose->m_boneFlags.m_data;
        v64 = v63[i];
        if ( (v64 & 4) != 0 )
          v63[i] = v64 & 0xFFFFFFF9 | 2;
      }
      ++v8;
      ++v5;
      v66 = v8;
      v75 = v5;
      p_m_quad = &mHavokPose->m_modelPose.m_data[v19].m_translation.m_quad;
      *p_m_quad = v36;
      p_m_quad[1] = v39;
      p_m_quad[2] = v21;
      mHavokPose->m_boneFlags.m_data[v19] = 1;
      mHavokPose->m_localInSync.m_bool = 0;
      if ( v8 >= v9 )
        break;
      v17 = v71;
      v16 = v70;
      v15 = v69.m_quad;
      v7 = this;
    }
  }
}

// File Line: 517
// RVA: 0x1BBD50
hkQsTransformf *__fastcall SkeletalPose::GetTranslationMS(SkeletalPose *this, int boneID)
{
  hkaPose *mHavokPose; // r8

  mHavokPose = this->mHavokPose;
  if ( (mHavokPose->m_boneFlags.m_data[boneID] & 2) != 0 )
    return hkaPose::calculateBoneModelSpace(mHavokPose, boneID);
  else
    return &mHavokPose->m_modelPose.m_data[boneID];
}

// File Line: 526
// RVA: 0x1BBA30
void __fastcall SkeletalPose::GetPositionMS(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixMS)
{
  hkaPose *mHavokPose; // r9
  hkQsTransformf *v5; // rax

  mHavokPose = this->mHavokPose;
  if ( (mHavokPose->m_boneFlags.m_data[boneID] & 2) != 0 )
  {
    v5 = hkaPose::calculateBoneModelSpace(mHavokPose, boneID);
    hkQsTransformf::get4x4ColumnMajor(v5, &matrixMS->v0.x);
  }
  else
  {
    hkQsTransformf::get4x4ColumnMajor(&mHavokPose->m_modelPose.m_data[boneID], &matrixMS->v0.x);
  }
}

// File Line: 536
// RVA: 0x1BBA90
void __fastcall SkeletalPose::GetPositionMS_ReNormalize(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixMS)
{
  hkaPose *mHavokPose; // r9
  hkQsTransformf *v5; // rax
  __m128 m_quad; // xmm3
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  hkQsTransformf v11; // [rsp+20h] [rbp-38h] BYREF

  mHavokPose = this->mHavokPose;
  if ( (mHavokPose->m_boneFlags.m_data[boneID] & 2) != 0 )
    v5 = hkaPose::calculateBoneModelSpace(mHavokPose, boneID);
  else
    v5 = &mHavokPose->m_modelPose.m_data[boneID];
  v11.m_translation = v5->m_translation;
  m_quad = v5->m_rotation.m_vec.m_quad;
  v7 = _mm_mul_ps(m_quad, m_quad);
  v8 = _mm_add_ps(_mm_shuffle_ps(v7, v7, 78), v7);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 177), v8);
  v10 = _mm_rsqrt_ps(v9);
  v11.m_scale = (hkVector4f)_xmm;
  v11.m_rotation.m_vec.m_quad = _mm_mul_ps(
                                  m_quad,
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                                    _mm_mul_ps(*(__m128 *)_xmm, v10)));
  hkQsTransformf::get4x4ColumnMajor(&v11, &matrixMS->v0.x);
}

// File Line: 569
// RVA: 0x1BDF10
void __fastcall SkeletalPose::SetQsTransformMS(SkeletalPose *this, int boneID, hkQsTransformf *transformMS)
{
  hkaPose *mHavokPose; // rsi
  hkQsTransformf *v4; // r9
  __int64 v5; // r8
  __int64 m_size; // rcx
  int v7; // eax
  __int64 v8; // r14
  __int64 v9; // r13
  __int64 v10; // rbp
  __int64 v11; // rdx
  unsigned int *m_data; // rcx
  hkQsTransformf *v13; // r12
  hkQsTransformf *v14; // r15
  hkQsTransformf *v15; // rdi
  __m128 m_quad; // xmm3
  __m128i inserted; // xmm0
  __m128 v18; // xmm6
  __m128 v19; // xmm8
  __m128 v20; // xmm0
  __m128 v21; // xmm8
  __m128 v22; // xmm1
  __m128 v23; // xmm7
  __m128 v24; // xmm5
  __m128i v25; // xmm9
  __m128 v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // xmm2
  __m128 v29; // xmm2
  __m128 v30; // xmm3
  __m128 v31; // xmm4
  __m128 v32; // xmm1
  __m128 v33; // xmm8
  __m128 v34; // xmm4
  __m128 v35; // xmm4
  __int64 i; // rcx
  unsigned int *v37; // rdx
  unsigned int v38; // eax
  hkVector4f *p_m_translation; // rax
  hkVector4f v40; // [rsp+20h] [rbp-A8h] BYREF
  int v41; // [rsp+D8h] [rbp+10h]
  __int64 v43; // [rsp+E8h] [rbp+20h]

  if ( boneID >= 0 )
  {
    mHavokPose = this->mHavokPose;
    v4 = transformMS;
    v5 = boneID;
    m_size = mHavokPose->m_skeleton->m_bones.m_size;
    mHavokPose->m_boneFlags.m_data[boneID] |= 4u;
    v7 = boneID + 1;
    v43 = boneID;
    v8 = boneID + 1;
    v41 = boneID + 1;
    v9 = m_size;
    if ( v8 < m_size )
    {
      v10 = v7;
      do
      {
        LOWORD(v11) = mHavokPose->m_skeleton->m_parentIndices.m_data[v8];
        if ( (_WORD)v11 != 0xFFFF )
        {
          m_data = mHavokPose->m_boneFlags.m_data;
          if ( (m_data[(__int16)v11] & 4) != 0 )
          {
            if ( (m_data[v8] & 1) != 0 )
            {
              v13 = mHavokPose->m_modelPose.m_data;
              v11 = (__int16)v11;
              if ( (m_data[(__int16)v11] & 2) != 0 )
                v14 = hkaPose::calculateBoneModelSpace(mHavokPose, v11);
              else
                v14 = &v13[v11];
              v15 = mHavokPose->m_localPose.m_data;
              hkVector4f::setRotatedInverseDir(&v40, &v14->m_rotation, &v14->m_translation);
              m_quad = v13[v10].m_translation.m_quad;
              inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
              v18 = (__m128)_mm_shuffle_epi32(inserted, 0);
              v19 = (__m128)_mm_shuffle_epi32(inserted, 64);
              v20 = v14->m_scale.m_quad;
              v21 = _mm_xor_ps(v19, v14->m_rotation.m_vec.m_quad);
              v22 = _mm_rcp_ps(v20);
              v23 = _mm_shuffle_ps(v21, v21, 255);
              v24 = _mm_shuffle_ps(v21, v21, 201);
              v25 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v22)), v22), 4);
              v26 = _mm_mul_ps(m_quad, v21);
              v27 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v21), _mm_mul_ps(v24, m_quad));
              v28 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                            _mm_shuffle_ps(v26, v26, 170)),
                          v21),
                        _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v23, v23), (__m128)xmmword_141A711B0), m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v23));
              v15[v10].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v28, v28), _mm_xor_ps(v18, v40.m_quad));
              v29 = v13[v10].m_rotation.m_vec.m_quad;
              v30 = _mm_shuffle_ps(v29, v29, 255);
              v31 = _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v21);
              v32 = _mm_mul_ps(v30, v21);
              v33 = _mm_mul_ps(v21, v29);
              v34 = _mm_sub_ps(v31, _mm_mul_ps(v24, v29));
              v35 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v34, v34, 201), _mm_mul_ps(v23, v29)), v32);
              v15[v10].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                   v35,
                                                   _mm_unpackhi_ps(
                                                     v35,
                                                     _mm_sub_ps(
                                                       _mm_mul_ps(v30, v23),
                                                       _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_shuffle_ps(v33, v33, 85),
                                                           _mm_shuffle_ps(v33, v33, 0)),
                                                         _mm_shuffle_ps(v33, v33, 170)))),
                                                   196);
              v15[v10].m_scale.m_quad = _mm_mul_ps(v13[v10].m_scale.m_quad, (__m128)_mm_srli_si128(v25, 4));
              mHavokPose->m_boneFlags.m_data[v8] &= ~1u;
            }
            mHavokPose->m_boneFlags.m_data[v8] |= 4u;
            mHavokPose->m_modelInSync.m_bool = 0;
          }
        }
        ++v8;
        ++v10;
      }
      while ( v8 < v9 );
      v5 = v43;
      v4 = transformMS;
      v7 = v41;
    }
    for ( i = v7; i < v9; ++i )
    {
      v37 = mHavokPose->m_boneFlags.m_data;
      v38 = v37[i];
      if ( (v38 & 4) != 0 )
        v37[i] = v38 & 0xFFFFFFF9 | 2;
    }
    p_m_translation = &mHavokPose->m_modelPose.m_data[v5].m_translation;
    *p_m_translation = v4->m_translation;
    p_m_translation[1] = v4->m_rotation.m_vec;
    p_m_translation[2] = v4->m_scale;
    mHavokPose->m_boneFlags.m_data[v5] = 1;
    mHavokPose->m_localInSync.m_bool = 0;
  }
}

// File Line: 579
// RVA: 0x1BC940
void __fastcall SkeletalPose::SetPositionMS(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixMS)
{
  __int64 v4; // rbx
  hkaPose *mHavokPose; // rsi
  __int64 v6; // r8
  __int64 m_size; // rcx
  int v8; // eax
  __int64 v9; // r13
  __int64 v10; // r14
  __int64 v11; // rbp
  __int64 v12; // rdx
  unsigned int *m_data; // rcx
  hkQsTransformf *v14; // r12
  hkQsTransformf *v15; // r15
  hkQsTransformf *v16; // rdi
  __m128 m_quad; // xmm3
  __m128i inserted; // xmm0
  __m128 v19; // xmm6
  __m128 v20; // xmm8
  __m128 v21; // xmm0
  __m128 v22; // xmm8
  __m128 v23; // xmm1
  __m128 v24; // xmm7
  __m128 v25; // xmm5
  __m128i v26; // xmm9
  __m128 v27; // xmm1
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  __m128 v30; // xmm2
  __m128 v31; // xmm3
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  __m128 v34; // xmm8
  __m128 v35; // xmm4
  __m128 v36; // xmm4
  __int64 i; // rcx
  unsigned int *v38; // rdx
  unsigned int v39; // eax
  hkQsTransformf v40; // [rsp+20h] [rbp-E8h] BYREF
  hkTransformf transform; // [rsp+50h] [rbp-B8h] BYREF

  if ( boneID >= 0 )
  {
    v4 = boneID;
    hkTransformf::set4x4ColumnMajor(&transform, &matrixMS->v0.x);
    hkQsTransformf::setFromTransformNoScale(&v40, &transform);
    mHavokPose = this->mHavokPose;
    v6 = v4;
    m_size = mHavokPose->m_skeleton->m_bones.m_size;
    mHavokPose->m_boneFlags.m_data[v4] |= 4u;
    v8 = v4 + 1;
    v9 = m_size;
    v10 = (int)v4 + 1;
    if ( v10 < m_size )
    {
      v11 = v8;
      do
      {
        LOWORD(v12) = mHavokPose->m_skeleton->m_parentIndices.m_data[v10];
        if ( (_WORD)v12 != 0xFFFF )
        {
          m_data = mHavokPose->m_boneFlags.m_data;
          if ( (m_data[(__int16)v12] & 4) != 0 )
          {
            if ( (m_data[v10] & 1) != 0 )
            {
              v14 = mHavokPose->m_modelPose.m_data;
              v12 = (__int16)v12;
              if ( (m_data[(__int16)v12] & 2) != 0 )
                v15 = hkaPose::calculateBoneModelSpace(mHavokPose, v12);
              else
                v15 = &v14[v12];
              v16 = mHavokPose->m_localPose.m_data;
              hkVector4f::setRotatedInverseDir(&transform.m_rotation.m_col0, &v15->m_rotation, &v15->m_translation);
              m_quad = v14[v11].m_translation.m_quad;
              inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
              v19 = (__m128)_mm_shuffle_epi32(inserted, 0);
              v20 = (__m128)_mm_shuffle_epi32(inserted, 64);
              v21 = v15->m_scale.m_quad;
              v22 = _mm_xor_ps(v20, v15->m_rotation.m_vec.m_quad);
              v23 = _mm_rcp_ps(v21);
              v24 = _mm_shuffle_ps(v22, v22, 255);
              v25 = _mm_shuffle_ps(v22, v22, 201);
              v26 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v21, v23)), v23), 4);
              v27 = _mm_mul_ps(v22, m_quad);
              v28 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v22), _mm_mul_ps(v25, m_quad));
              v29 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                            _mm_shuffle_ps(v27, v27, 170)),
                          v22),
                        _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v24, v24), (__m128)xmmword_141A711B0), m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v24));
              v16[v11].m_translation.m_quad = _mm_add_ps(
                                                _mm_add_ps(v29, v29),
                                                _mm_xor_ps(v19, transform.m_rotation.m_col0.m_quad));
              v30 = v14[v11].m_rotation.m_vec.m_quad;
              v31 = _mm_shuffle_ps(v30, v30, 255);
              v32 = _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v22);
              v33 = _mm_mul_ps(v31, v22);
              v34 = _mm_mul_ps(v22, v30);
              v35 = _mm_sub_ps(v32, _mm_mul_ps(v25, v30));
              v36 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v35, v35, 201), _mm_mul_ps(v24, v30)), v33);
              v16[v11].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                   v36,
                                                   _mm_unpackhi_ps(
                                                     v36,
                                                     _mm_sub_ps(
                                                       _mm_mul_ps(v31, v24),
                                                       _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_shuffle_ps(v34, v34, 85),
                                                           _mm_shuffle_ps(v34, v34, 0)),
                                                         _mm_shuffle_ps(v34, v34, 170)))),
                                                   196);
              v16[v11].m_scale.m_quad = _mm_mul_ps(v14[v11].m_scale.m_quad, (__m128)_mm_srli_si128(v26, 4));
              mHavokPose->m_boneFlags.m_data[v10] &= ~1u;
            }
            mHavokPose->m_boneFlags.m_data[v10] |= 4u;
            mHavokPose->m_modelInSync.m_bool = 0;
          }
        }
        ++v10;
        ++v11;
      }
      while ( v10 < v9 );
      v8 = v4 + 1;
      v6 = v4;
    }
    for ( i = v8; i < v9; ++i )
    {
      v38 = mHavokPose->m_boneFlags.m_data;
      v39 = v38[i];
      if ( (v39 & 4) != 0 )
        v38[i] = v39 & 0xFFFFFFF9 | 2;
    }
    mHavokPose->m_modelPose.m_data[v6] = v40;
    mHavokPose->m_boneFlags.m_data[v6] = 1;
    mHavokPose->m_localInSync.m_bool = 0;
  }
}

// File Line: 594
// RVA: 0x1BCCD0
void __fastcall SkeletalPose::SetPositionMS_ReNormalize(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixMS)
{
  __int64 v4; // rbx
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  hkaPose *mHavokPose; // rsi
  __int64 v10; // r8
  __int64 m_size; // rcx
  int v12; // eax
  __int64 v13; // r13
  __int64 v14; // r14
  __int64 v15; // rbp
  __int64 v16; // rdx
  unsigned int *m_data; // rcx
  hkQsTransformf *v18; // r12
  hkQsTransformf *v19; // r15
  hkQsTransformf *v20; // rdi
  __m128 m_quad; // xmm3
  __m128i inserted; // xmm0
  __m128 v23; // xmm6
  __m128 v24; // xmm8
  __m128 v25; // xmm0
  __m128 v26; // xmm8
  __m128 v27; // xmm1
  __m128 v28; // xmm7
  __m128 v29; // xmm5
  __m128i v30; // xmm9
  __m128 v31; // xmm1
  __m128 v32; // xmm4
  __m128 v33; // xmm2
  __m128 v34; // xmm2
  __m128 v35; // xmm3
  __m128 v36; // xmm4
  __m128 v37; // xmm1
  __m128 v38; // xmm8
  __m128 v39; // xmm4
  __m128 v40; // xmm4
  __int64 i; // rcx
  unsigned int *v42; // rdx
  unsigned int v43; // eax
  hkQsTransformf v44; // [rsp+20h] [rbp-E8h] BYREF
  hkTransformf transform; // [rsp+50h] [rbp-B8h] BYREF

  if ( boneID >= 0 )
  {
    v4 = boneID;
    hkTransformf::set4x4ColumnMajor(&transform, &matrixMS->v0.x);
    hkQsTransformf::setFromTransformNoScale(&v44, &transform);
    if ( sNormalize )
    {
      v5 = _mm_mul_ps(v44.m_rotation.m_vec.m_quad, v44.m_rotation.m_vec.m_quad);
      v6 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 78), v5);
      v7 = _mm_add_ps(_mm_shuffle_ps(v6, v6, 177), v6);
      v8 = _mm_rsqrt_ps(v7);
      v44.m_scale = (hkVector4f)_xmm;
      v44.m_rotation.m_vec.m_quad = _mm_mul_ps(
                                      v44.m_rotation.m_vec.m_quad,
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)),
                                        _mm_mul_ps(*(__m128 *)_xmm, v8)));
    }
    mHavokPose = this->mHavokPose;
    v10 = v4;
    m_size = mHavokPose->m_skeleton->m_bones.m_size;
    mHavokPose->m_boneFlags.m_data[v4] |= 4u;
    v12 = v4 + 1;
    v13 = m_size;
    v14 = (int)v4 + 1;
    if ( v14 < m_size )
    {
      v15 = v12;
      do
      {
        LOWORD(v16) = mHavokPose->m_skeleton->m_parentIndices.m_data[v14];
        if ( (_WORD)v16 != 0xFFFF )
        {
          m_data = mHavokPose->m_boneFlags.m_data;
          if ( (m_data[(__int16)v16] & 4) != 0 )
          {
            if ( (m_data[v14] & 1) != 0 )
            {
              v18 = mHavokPose->m_modelPose.m_data;
              v16 = (__int16)v16;
              if ( (m_data[(__int16)v16] & 2) != 0 )
                v19 = hkaPose::calculateBoneModelSpace(mHavokPose, v16);
              else
                v19 = &v18[v16];
              v20 = mHavokPose->m_localPose.m_data;
              hkVector4f::setRotatedInverseDir(&transform.m_rotation.m_col0, &v19->m_rotation, &v19->m_translation);
              m_quad = v18[v15].m_translation.m_quad;
              inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
              v23 = (__m128)_mm_shuffle_epi32(inserted, 0);
              v24 = (__m128)_mm_shuffle_epi32(inserted, 64);
              v25 = v19->m_scale.m_quad;
              v26 = _mm_xor_ps(v24, v19->m_rotation.m_vec.m_quad);
              v27 = _mm_rcp_ps(v25);
              v28 = _mm_shuffle_ps(v26, v26, 255);
              v29 = _mm_shuffle_ps(v26, v26, 201);
              v30 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v25, v27)), v27), 4);
              v31 = _mm_mul_ps(v26, m_quad);
              v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v26), _mm_mul_ps(v29, m_quad));
              v33 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                            _mm_shuffle_ps(v31, v31, 170)),
                          v26),
                        _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v28, v28), (__m128)xmmword_141A711B0), m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v28));
              v20[v15].m_translation.m_quad = _mm_add_ps(
                                                _mm_add_ps(v33, v33),
                                                _mm_xor_ps(v23, transform.m_rotation.m_col0.m_quad));
              v34 = v18[v15].m_rotation.m_vec.m_quad;
              v35 = _mm_shuffle_ps(v34, v34, 255);
              v36 = _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v26);
              v37 = _mm_mul_ps(v26, v35);
              v38 = _mm_mul_ps(v26, v34);
              v39 = _mm_sub_ps(v36, _mm_mul_ps(v29, v34));
              v40 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v39, v39, 201), _mm_mul_ps(v28, v34)), v37);
              v20[v15].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                   v40,
                                                   _mm_unpackhi_ps(
                                                     v40,
                                                     _mm_sub_ps(
                                                       _mm_mul_ps(v35, v28),
                                                       _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_shuffle_ps(v38, v38, 85),
                                                           _mm_shuffle_ps(v38, v38, 0)),
                                                         _mm_shuffle_ps(v38, v38, 170)))),
                                                   196);
              v20[v15].m_scale.m_quad = _mm_mul_ps(v18[v15].m_scale.m_quad, (__m128)_mm_srli_si128(v30, 4));
              mHavokPose->m_boneFlags.m_data[v14] &= ~1u;
            }
            mHavokPose->m_boneFlags.m_data[v14] |= 4u;
            mHavokPose->m_modelInSync.m_bool = 0;
          }
        }
        ++v14;
        ++v15;
      }
      while ( v14 < v13 );
      v12 = v4 + 1;
      v10 = v4;
    }
    for ( i = v12; i < v13; ++i )
    {
      v42 = mHavokPose->m_boneFlags.m_data;
      v43 = v42[i];
      if ( (v43 & 4) != 0 )
        v42[i] = v43 & 0xFFFFFFF9 | 2;
    }
    mHavokPose->m_modelPose.m_data[v10] = v44;
    mHavokPose->m_boneFlags.m_data[v10] = 1;
    mHavokPose->m_localInSync.m_bool = 0;
  }
}

// File Line: 619
// RVA: 0x1BB790
void __fastcall SkeletalPose::GetPositionLS(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixLS)
{
  hkaPose *mHavokPose; // r14
  __int64 v4; // r15
  unsigned int *m_data; // r9
  hkQsTransformf *v7; // rcx
  __int64 v8; // rsi
  __int16 v9; // ax
  hkQsTransformf *v10; // r12
  hkQsTransformf *v11; // rbp
  hkQsTransformf *v12; // rdi
  __m128 m_quad; // xmm3
  __m128i inserted; // xmm0
  __m128 v15; // xmm6
  __m128 v16; // xmm8
  __m128 v17; // xmm0
  __m128 v18; // xmm8
  __m128 v19; // xmm1
  __m128 v20; // xmm7
  __m128 v21; // xmm5
  __m128i v22; // xmm9
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm8
  __m128 v31; // xmm4
  __m128 v32; // xmm4
  hkQsTransformf *v33; // rax
  hkVector4f v34; // [rsp+20h] [rbp-98h] BYREF

  mHavokPose = this->mHavokPose;
  v4 = boneID;
  m_data = mHavokPose->m_boneFlags.m_data;
  if ( (m_data[boneID] & 1) != 0 )
  {
    v8 = boneID;
    v9 = mHavokPose->m_skeleton->m_parentIndices.m_data[boneID];
    v10 = mHavokPose->m_modelPose.m_data;
    if ( v9 == -1 )
    {
      v33 = mHavokPose->m_localPose.m_data;
      v33[boneID].m_translation = v10[boneID].m_translation;
      v33[v8].m_rotation = v10[v8].m_rotation;
      v33[v8].m_scale = v10[v8].m_scale;
    }
    else
    {
      if ( (m_data[v9] & 2) != 0 )
        v11 = hkaPose::calculateBoneModelSpace(mHavokPose, v9);
      else
        v11 = &v10[v9];
      v12 = mHavokPose->m_localPose.m_data;
      hkVector4f::setRotatedInverseDir(&v34, &v11->m_rotation, &v11->m_translation);
      m_quad = v10[v4].m_translation.m_quad;
      inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v15 = (__m128)_mm_shuffle_epi32(inserted, 0);
      v16 = (__m128)_mm_shuffle_epi32(inserted, 64);
      v17 = v11->m_scale.m_quad;
      v18 = _mm_xor_ps(v16, v11->m_rotation.m_vec.m_quad);
      v19 = _mm_rcp_ps(v17);
      v20 = _mm_shuffle_ps(v18, v18, 255);
      v21 = _mm_shuffle_ps(v18, v18, 201);
      v22 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v19)), v19), 4);
      v23 = _mm_mul_ps(m_quad, v18);
      v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v18), _mm_mul_ps(v21, m_quad));
      v25 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                    _mm_shuffle_ps(v23, v23, 170)),
                  v18),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v20, v20), (__m128)xmmword_141A711B0), m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v20));
      v12[v8].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v25, v25), _mm_xor_ps(v15, v34.m_quad));
      v26 = v10[v8].m_rotation.m_vec.m_quad;
      v27 = _mm_shuffle_ps(v26, v26, 255);
      v28 = _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v18);
      v29 = _mm_mul_ps(v27, v18);
      v30 = _mm_mul_ps(v18, v26);
      v31 = _mm_sub_ps(v28, _mm_mul_ps(v21, v26));
      v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 201), _mm_mul_ps(v20, v26)), v29);
      v12[v8].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                          v32,
                                          _mm_unpackhi_ps(
                                            v32,
                                            _mm_sub_ps(
                                              _mm_mul_ps(v27, v20),
                                              _mm_add_ps(
                                                _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                                                _mm_shuffle_ps(v30, v30, 170)))),
                                          196);
      v12[v8].m_scale.m_quad = _mm_mul_ps(v10[v8].m_scale.m_quad, (__m128)_mm_srli_si128(v22, 4));
    }
    mHavokPose->m_boneFlags.m_data[v4] &= ~1u;
    v7 = &mHavokPose->m_localPose.m_data[v8];
  }
  else
  {
    v7 = &mHavokPose->m_localPose.m_data[boneID];
  }
  hkQsTransformf::get4x4ColumnMajor(v7, &matrixLS->v0.x);
}

// File Line: 629
// RVA: 0x1BBD20
hkQsTransformf *__fastcall SkeletalPose::GetQsTransformLS(SkeletalPose *this, int boneID)
{
  return &hkaPose::getSyncedPoseLocalSpace(this->mHavokPose)->m_data[boneID];
}

// File Line: 637
// RVA: 0x1BBB40
void __fastcall SkeletalPose::GetPositionRefS(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixRS)
{
  hkQsTransformf v3; // [rsp+20h] [rbp-38h] BYREF

  v3 = this->mHavokPose->m_skeleton->m_referencePose.m_data[boneID];
  hkQsTransformf::get4x4ColumnMajor(&v3, &matrixRS->v0.x);
}

// File Line: 653
// RVA: 0x1BC5B0
void __fastcall SkeletalPose::SetPositionLS(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixLS)
{
  __int64 v4; // rbx
  hkaPose *mHavokPose; // rsi
  __int64 v6; // r8
  __int64 m_size; // rcx
  int v8; // eax
  __int64 v9; // r13
  __int64 v10; // r14
  __int64 v11; // rbp
  __int64 v12; // rdx
  unsigned int *m_data; // rcx
  hkQsTransformf *v14; // r12
  hkQsTransformf *v15; // r15
  hkQsTransformf *v16; // rdi
  __m128 m_quad; // xmm3
  __m128 v18; // xmm2
  __m128i inserted; // xmm0
  __m128 v20; // xmm8
  __m128 v21; // xmm9
  __m128 v22; // xmm1
  __m128 v23; // xmm7
  __m128 v24; // xmm5
  __m128 v25; // xmm4
  __m128 v26; // xmm2
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm1
  __m128 v31; // xmm8
  __m128 v32; // xmm4
  __m128 v33; // xmm4
  __int64 i; // rcx
  unsigned int *v35; // rdx
  unsigned int v36; // eax
  hkQsTransformf v37; // [rsp+20h] [rbp-E8h] BYREF
  hkTransformf transform; // [rsp+50h] [rbp-B8h] BYREF

  if ( boneID >= 0 )
  {
    v4 = boneID;
    hkTransformf::set4x4ColumnMajor(&transform, &matrixLS->v0.x);
    hkQsTransformf::setFromTransformNoScale(&v37, &transform);
    mHavokPose = this->mHavokPose;
    v6 = v4;
    m_size = mHavokPose->m_skeleton->m_bones.m_size;
    mHavokPose->m_boneFlags.m_data[v4] |= 4u;
    v8 = v4 + 1;
    v9 = m_size;
    v10 = (int)v4 + 1;
    if ( v10 < m_size )
    {
      v11 = v8;
      do
      {
        LOWORD(v12) = mHavokPose->m_skeleton->m_parentIndices.m_data[v10];
        if ( (_WORD)v12 != 0xFFFF )
        {
          m_data = mHavokPose->m_boneFlags.m_data;
          if ( (m_data[(__int16)v12] & 4) != 0 )
          {
            if ( (m_data[v10] & 1) != 0 )
            {
              v14 = mHavokPose->m_modelPose.m_data;
              v12 = (__int16)v12;
              if ( (m_data[(__int16)v12] & 2) != 0 )
                v15 = hkaPose::calculateBoneModelSpace(mHavokPose, v12);
              else
                v15 = &v14[v12];
              v16 = mHavokPose->m_localPose.m_data;
              hkVector4f::setRotatedInverseDir(&transform.m_rotation.m_col0, &v15->m_rotation, &v15->m_translation);
              m_quad = v14[v11].m_translation.m_quad;
              v18 = _mm_rcp_ps(v15->m_scale.m_quad);
              inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
              v20 = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 64), v15->m_rotation.m_vec.m_quad);
              v21 = (__m128)_mm_srli_si128(
                              _mm_slli_si128(
                                (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v15->m_scale.m_quad)), v18),
                                4),
                              4);
              v22 = _mm_mul_ps(m_quad, v20);
              v23 = _mm_shuffle_ps(v20, v20, 255);
              v24 = _mm_shuffle_ps(v20, v20, 201);
              v25 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v20), _mm_mul_ps(m_quad, v24));
              v26 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                            _mm_shuffle_ps(v22, v22, 170)),
                          v20),
                        _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v23, v23), (__m128)xmmword_141A711B0), m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v23));
              v16[v11].m_translation.m_quad = _mm_add_ps(
                                                _mm_add_ps(v26, v26),
                                                _mm_xor_ps(
                                                  (__m128)_mm_shuffle_epi32(inserted, 0),
                                                  transform.m_rotation.m_col0.m_quad));
              v27 = v14[v11].m_rotation.m_vec.m_quad;
              v28 = _mm_shuffle_ps(v27, v27, 255);
              v29 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v20);
              v30 = _mm_mul_ps(v28, v20);
              v31 = _mm_mul_ps(v20, v27);
              v32 = _mm_sub_ps(v29, _mm_mul_ps(v24, v27));
              v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 201), _mm_mul_ps(v23, v27)), v30);
              v16[v11].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                   v33,
                                                   _mm_unpackhi_ps(
                                                     v33,
                                                     _mm_sub_ps(
                                                       _mm_mul_ps(v28, v23),
                                                       _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_shuffle_ps(v31, v31, 85),
                                                           _mm_shuffle_ps(v31, v31, 0)),
                                                         _mm_shuffle_ps(v31, v31, 170)))),
                                                   196);
              v16[v11].m_scale.m_quad = _mm_mul_ps(v14[v11].m_scale.m_quad, v21);
              mHavokPose->m_boneFlags.m_data[v10] &= ~1u;
            }
            mHavokPose->m_boneFlags.m_data[v10] |= 4u;
            mHavokPose->m_modelInSync.m_bool = 0;
          }
        }
        ++v10;
        ++v11;
      }
      while ( v10 < v9 );
      v8 = v4 + 1;
      v6 = v4;
    }
    for ( i = v8; i < v9; ++i )
    {
      v35 = mHavokPose->m_boneFlags.m_data;
      v36 = v35[i];
      if ( (v36 & 4) != 0 )
        v35[i] = v36 & 0xFFFFFFF9 | 2;
    }
    mHavokPose->m_localPose.m_data[v6] = v37;
    mHavokPose->m_boneFlags.m_data[v6] = 2;
    mHavokPose->m_modelInSync.m_bool = 0;
  }
}

// File Line: 676
// RVA: 0x1BDBA0
void __fastcall SkeletalPose::SetQsTransformLS(SkeletalPose *this, int boneID, hkQsTransformf *matrixLS)
{
  hkaPose *mHavokPose; // rsi
  hkQsTransformf *v4; // r9
  __int64 v5; // r8
  __int64 m_size; // rcx
  int v7; // eax
  __int64 v8; // r14
  __int64 v9; // r13
  __int64 v10; // rbp
  __int64 v11; // rdx
  unsigned int *m_data; // rcx
  hkQsTransformf *v13; // r12
  hkQsTransformf *v14; // r15
  hkQsTransformf *v15; // rdi
  __m128 m_quad; // xmm3
  __m128 v17; // xmm2
  __m128i inserted; // xmm0
  __m128 v19; // xmm8
  __m128 v20; // xmm9
  __m128 v21; // xmm1
  __m128 v22; // xmm7
  __m128 v23; // xmm5
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm8
  __m128 v31; // xmm4
  __m128 v32; // xmm4
  __int64 i; // rcx
  unsigned int *v34; // rdx
  unsigned int v35; // eax
  hkVector4f *p_m_translation; // rax
  hkVector4f v37; // [rsp+20h] [rbp-A8h] BYREF
  int v38; // [rsp+D8h] [rbp+10h]
  __int64 v40; // [rsp+E8h] [rbp+20h]

  if ( boneID >= 0 )
  {
    mHavokPose = this->mHavokPose;
    v4 = matrixLS;
    v5 = boneID;
    m_size = mHavokPose->m_skeleton->m_bones.m_size;
    mHavokPose->m_boneFlags.m_data[boneID] |= 4u;
    v7 = boneID + 1;
    v40 = boneID;
    v8 = boneID + 1;
    v38 = boneID + 1;
    v9 = m_size;
    if ( v8 < m_size )
    {
      v10 = v7;
      do
      {
        LOWORD(v11) = mHavokPose->m_skeleton->m_parentIndices.m_data[v8];
        if ( (_WORD)v11 != 0xFFFF )
        {
          m_data = mHavokPose->m_boneFlags.m_data;
          if ( (m_data[(__int16)v11] & 4) != 0 )
          {
            if ( (m_data[v8] & 1) != 0 )
            {
              v13 = mHavokPose->m_modelPose.m_data;
              v11 = (__int16)v11;
              if ( (m_data[(__int16)v11] & 2) != 0 )
                v14 = hkaPose::calculateBoneModelSpace(mHavokPose, v11);
              else
                v14 = &v13[v11];
              v15 = mHavokPose->m_localPose.m_data;
              hkVector4f::setRotatedInverseDir(&v37, &v14->m_rotation, &v14->m_translation);
              m_quad = v13[v10].m_translation.m_quad;
              v17 = _mm_rcp_ps(v14->m_scale.m_quad);
              inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
              v19 = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 64), v14->m_rotation.m_vec.m_quad);
              v20 = (__m128)_mm_srli_si128(
                              _mm_slli_si128(
                                (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v14->m_scale.m_quad)), v17),
                                4),
                              4);
              v21 = _mm_mul_ps(m_quad, v19);
              v22 = _mm_shuffle_ps(v19, v19, 255);
              v23 = _mm_shuffle_ps(v19, v19, 201);
              v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v19), _mm_mul_ps(m_quad, v23));
              v25 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                            _mm_shuffle_ps(v21, v21, 170)),
                          v19),
                        _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v22, v22), (__m128)xmmword_141A711B0), m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v22));
              v15[v10].m_translation.m_quad = _mm_add_ps(
                                                _mm_add_ps(v25, v25),
                                                _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 0), v37.m_quad));
              v26 = v13[v10].m_rotation.m_vec.m_quad;
              v27 = _mm_shuffle_ps(v26, v26, 255);
              v28 = _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v19);
              v29 = _mm_mul_ps(v27, v19);
              v30 = _mm_mul_ps(v19, v26);
              v31 = _mm_sub_ps(v28, _mm_mul_ps(v23, v26));
              v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 201), _mm_mul_ps(v22, v26)), v29);
              v15[v10].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                   v32,
                                                   _mm_unpackhi_ps(
                                                     v32,
                                                     _mm_sub_ps(
                                                       _mm_mul_ps(v27, v22),
                                                       _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_shuffle_ps(v30, v30, 85),
                                                           _mm_shuffle_ps(v30, v30, 0)),
                                                         _mm_shuffle_ps(v30, v30, 170)))),
                                                   196);
              v15[v10].m_scale.m_quad = _mm_mul_ps(v13[v10].m_scale.m_quad, v20);
              mHavokPose->m_boneFlags.m_data[v8] &= ~1u;
            }
            mHavokPose->m_boneFlags.m_data[v8] |= 4u;
            mHavokPose->m_modelInSync.m_bool = 0;
          }
        }
        ++v8;
        ++v10;
      }
      while ( v8 < v9 );
      v5 = v40;
      v4 = matrixLS;
      v7 = v38;
    }
    for ( i = v7; i < v9; ++i )
    {
      v34 = mHavokPose->m_boneFlags.m_data;
      v35 = v34[i];
      if ( (v35 & 4) != 0 )
        v34[i] = v35 & 0xFFFFFFF9 | 2;
    }
    p_m_translation = &mHavokPose->m_localPose.m_data[v5].m_translation;
    *p_m_translation = v4->m_translation;
    p_m_translation[1] = v4->m_rotation.m_vec;
    p_m_translation[2] = v4->m_scale;
    mHavokPose->m_boneFlags.m_data[v5] = 2;
    mHavokPose->m_modelInSync.m_bool = 0;
  }
}

// File Line: 690
// RVA: 0x1BACB0
// local variable allocation has failed, the output may be wrong!
void __fastcall SkeletalPose::DebugDraw(SkeletalPose *this, UFG::qColour *colour, double fScale)
{
  UFG::qColour *v3; // rbx
  SkeletalPose *v4; // rsi
  Skeleton *mUFGSkeleton; // rdi
  hkaSkeleton *m_skeleton; // r14
  unsigned int m_size; // r9d
  unsigned int v8; // r8d
  bool *v9; // rcx
  unsigned int *mBoneNameHashIDs; // rdi
  unsigned int v11; // r10d
  unsigned int v12; // r11d
  unsigned int v13; // ebx
  bool v14; // r14
  unsigned int v15; // r15d
  bool v16; // dl
  unsigned int v17; // r12d
  unsigned int v18; // r13d
  unsigned int v19; // eax
  __m128 v20; // xmm1
  _QWORD **Value; // rax
  __int64 v22; // rax
  hkaPose *v23; // rbx
  int v24; // edi
  int v25; // esi
  int v26; // eax
  int v27; // eax
  int v28; // r9d
  int v29; // eax
  int v30; // eax
  int v31; // r9d
  int v32; // eax
  int v33; // eax
  int v34; // r9d
  int v35; // esi
  int v36; // r9d
  int v37; // eax
  int v38; // eax
  int v39; // r9d
  int v40; // edx
  float *v41; // rdi
  __int64 v42; // rcx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v43; // rax
  __int64 v44; // rdi
  __m128 v45; // xmm1
  __int64 v46; // rdx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v47; // rax
  _QWORD **v48; // rax
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *SyncedPoseModelSpace; // rax
  hkResult v50; // [rsp+30h] [rbp-D0h] BYREF
  hkResult v51; // [rsp+34h] [rbp-CCh] BYREF
  hkResult v52; // [rsp+38h] [rbp-C8h] BYREF
  hkResult v53; // [rsp+3Ch] [rbp-C4h] BYREF
  hkResult v54; // [rsp+40h] [rbp-C0h] BYREF
  hkResult v55; // [rsp+44h] [rbp-BCh] BYREF
  hkaSkeleton *skeleton; // [rsp+48h] [rbp-B8h]
  __int64 v57; // [rsp+50h] [rbp-B0h]
  __int64 v58; // [rsp+58h] [rbp-A8h]
  hkTransformf transform; // [rsp+60h] [rbp-A0h] BYREF
  bool boneDraw[176]; // [rsp+A0h] [rbp-60h] BYREF
  hkResult result; // [rsp+1C0h] [rbp+C0h] BYREF
  hkResult v64; // [rsp+1C8h] [rbp+C8h] BYREF

  v58 = -2i64;
  v3 = colour;
  v4 = this;
  SkeletalPose::syncTransformToRoot(this);
  mUFGSkeleton = v4->mRigHandle.mUFGSkeleton;
  m_skeleton = v4->mHavokPose->m_skeleton;
  skeleton = m_skeleton;
  m_size = m_skeleton->m_bones.m_size;
  v8 = 0;
  if ( m_size )
  {
    v9 = boneDraw;
    mBoneNameHashIDs = mUFGSkeleton->mBoneNameHashIDs;
    v11 = s_uDirectionUID_0;
    v12 = s_uSync01UID_0;
    v13 = s_uBalanceUID_0;
    v14 = sShowShoulders;
    v15 = s_uBip01_R_ClavicleUID_0;
    v16 = sShowTwistOnly;
    v17 = s_uBip01_R_UpperArmUID_0;
    v18 = s_ur_upperarm_twistUID_0;
    do
    {
      v19 = *mBoneNameHashIDs;
      if ( v8 < 2 || v19 == v11 || v19 == v12 || v19 == v13 )
        *v9 = 1;
      if ( v14
        && (v19 == v15 && !v16
         || v19 == v17
         || v19 == v18
         || v19 == s_ur_shoulder_jointUID_0 && !v16
         || v19 == s_uBip01_L_ClavicleUID_0 && !v16
         || v19 == s_uBip01_L_UpperArmUID_0
         || v19 == s_ul_upperarm_twistUID_0
         || v19 == s_ul_shoulder_jointUID_0 && !v16) )
      {
        *v9 = 1;
      }
      *v9 = sShowForearms
         && (v19 == s_R_Forearm_UID_0
          || v19 == s_R_Hand_UID_0
          || v19 == s_R_ForeTwist_UID_0
          || v19 == s_L_Forearm_UID_0
          || v19 == s_L_Hand_UID_0
          || v19 == s_L_ForeTwist_UID_0);
      ++v8;
      ++mBoneNameHashIDs;
      ++v9;
    }
    while ( v8 < m_size );
    m_skeleton = skeleton;
    v3 = colour;
  }
  v20 = *(__m128 *)&fScale;
  v20.m128_f32[0] = *(float *)&fScale - 1.0;
  if ( (float)(*(float *)&fScale - 1.0) < 0.0 )
    v20 = _mm_xor_ps(v20, *(__m128 *)_xmm);
  if ( v20.m128_f32[0] < 0.001 )
  {
    if ( v4->mIsRootDirty )
    {
      hkTransformf::set4x4ColumnMajor(&transform, &v4->mRootMatrix44.v0.x);
      hkQsTransformf::setFromTransformNoScale(&v4->mRootQsMatrix, &transform);
      v4->mIsRootDirty = 0;
    }
    SyncedPoseModelSpace = hkaPose::getSyncedPoseModelSpace(v4->mHavokPose);
    DrawBoneHavok(m_skeleton, SyncedPoseModelSpace->m_data, &v4->mRootQsMatrix, boneDraw, v3);
  }
  else
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
    v23 = (hkaPose *)v22;
    v57 = v22;
    if ( v22 )
    {
      *(_QWORD *)v22 = m_skeleton;
      *(_QWORD *)(v22 + 8) = 0i64;
      *(_DWORD *)(v22 + 16) = 0;
      *(_DWORD *)(v22 + 20) = 0x80000000;
      *(_QWORD *)(v22 + 24) = 0i64;
      *(_DWORD *)(v22 + 32) = 0;
      *(_DWORD *)(v22 + 36) = 0x80000000;
      *(_QWORD *)(v22 + 40) = 0i64;
      *(_DWORD *)(v22 + 48) = 0;
      *(_DWORD *)(v22 + 52) = 0x80000000;
      *(_WORD *)(v22 + 56) = 0;
      *(_QWORD *)(v22 + 64) = 0i64;
      *(_DWORD *)(v22 + 72) = 0;
      *(_DWORD *)(v22 + 76) = 0x80000000;
      v24 = *(_DWORD *)(*(_QWORD *)v22 + 48i64);
      v25 = (v24 + 3) & 0xFFFFFFFC;
      if ( (*(_DWORD *)(v22 + 36) & 0x3FFFFFFF) >= v25 )
        result.m_enum = HK_SUCCESS;
      else
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (void *)(v22 + 24), v25, 48);
      if ( (v23->m_localPose.m_capacityAndFlags & 0x3FFFFFFF) >= v25 )
        v64.m_enum = HK_SUCCESS;
      else
        hkArrayUtil::_reserve(&v64, &hkContainerHeapAllocator::s_alloc, &v23->m_localPose, v25, 48);
      if ( (v23->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) >= v25 )
        v51.m_enum = HK_SUCCESS;
      else
        hkArrayUtil::_reserve(&v51, &hkContainerHeapAllocator::s_alloc, &v23->m_boneFlags, v25, 4);
      v26 = v23->m_modelPose.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v26 >= v24 )
      {
        v55.m_enum = HK_SUCCESS;
      }
      else
      {
        v27 = 2 * v26;
        v28 = v24;
        if ( v24 < v27 )
          v28 = v27;
        hkArrayUtil::_reserve(&v55, &hkContainerHeapAllocator::s_alloc, &v23->m_modelPose, v28, 48);
      }
      v23->m_modelPose.m_size = v24;
      v29 = v23->m_localPose.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v29 >= v24 )
      {
        v54.m_enum = HK_SUCCESS;
      }
      else
      {
        v30 = 2 * v29;
        v31 = v24;
        if ( v24 < v30 )
          v31 = v30;
        hkArrayUtil::_reserve(&v54, &hkContainerHeapAllocator::s_alloc, &v23->m_localPose, v31, 48);
      }
      v23->m_localPose.m_size = v24;
      v32 = v23->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v32 >= v24 )
      {
        v52.m_enum = HK_SUCCESS;
      }
      else
      {
        v33 = 2 * v32;
        v34 = v24;
        if ( v24 < v33 )
          v34 = v33;
        hkArrayUtil::_reserve(&v52, &hkContainerHeapAllocator::s_alloc, &v23->m_boneFlags, v34, 4);
      }
      v23->m_boneFlags.m_size = v24;
      v35 = v23->m_skeleton->m_floatSlots.m_size;
      v36 = (v35 + 3) & 0xFFFFFFFC;
      if ( (v23->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) >= v36 )
        v53.m_enum = HK_SUCCESS;
      else
        hkArrayUtil::_reserve(&v53, &hkContainerHeapAllocator::s_alloc, &v23->m_floatSlotValues, v36, 4);
      v37 = v23->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v37 >= v35 )
      {
        v50.m_enum = HK_SUCCESS;
      }
      else
      {
        v38 = 2 * v37;
        v39 = v35;
        if ( v35 < v38 )
          v39 = v38;
        hkArrayUtil::_reserve(&v50, &hkContainerHeapAllocator::s_alloc, &v23->m_floatSlotValues, v39, 4);
      }
      v40 = v35 - v23->m_floatSlotValues.m_size;
      v41 = &v23->m_floatSlotValues.m_data[v23->m_floatSlotValues.m_size];
      v42 = v40;
      if ( v40 > 0 )
      {
        while ( v42 )
        {
          *v41++ = 0.0;
          --v42;
        }
      }
      v23->m_floatSlotValues.m_size = v35;
      v4 = this;
    }
    else
    {
      v23 = 0i64;
    }
    hkaPose::operator=(v23, v4->mHavokPose);
    v43 = hkaPose::accessSyncedPoseLocalSpace(v23);
    v44 = v43->m_size;
    if ( v44 > 0 )
    {
      v20.m128_f32[0] = *(float *)&fScale;
      v45 = _mm_shuffle_ps(v20, v20, 0);
      v46 = 0i64;
      do
      {
        v43->m_data[v46].m_translation.m_quad = _mm_mul_ps(v45, v43->m_data[v46].m_translation.m_quad);
        ++v46;
        --v44;
      }
      while ( v44 );
    }
    if ( v4->mIsRootDirty )
    {
      hkTransformf::set4x4ColumnMajor(&transform, &v4->mRootMatrix44.v0.x);
      hkQsTransformf::setFromTransformNoScale(&v4->mRootQsMatrix, &transform);
      v4->mIsRootDirty = 0;
    }
    v47 = hkaPose::getSyncedPoseModelSpace(v23);
    DrawBoneHavok(skeleton, v47->m_data, &v4->mRootQsMatrix, boneDraw, colour);
    if ( v23 )
    {
      hkaPose::~hkaPose(v23);
      v48 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkaPose *, __int64))(*v48[11] + 16i64))(v48[11], v23, 80i64);
    }
  }
}

// File Line: 796
// RVA: 0x1BE590
void __fastcall blendPosehkQ(
        hkQsTransformf *poseLocalSpaceOutAcc,
        hkQsTransformf *posePose,
        unsigned int numBones,
        float weight,
        const float *perBoneWeights,
        __int16 *transformTrackToBoneIndices)
{
  __m128 v6; // xmm4
  __m128 v7; // xmm5
  int v8; // eax
  __int64 v9; // r9
  __int64 v10; // r11
  hkQuaternionf *p_m_rotation; // rax
  signed __int64 v12; // rdx
  float v13; // xmm0_4
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm0
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  signed __int64 v22; // rdx
  hkQuaternionf *v23; // rax
  __m128 v24; // xmm5
  __int64 v25; // r9
  __m128 v26; // xmm1
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  __m128 v29; // xmm4
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm2

  v8 = numBones - 1;
  v9 = (int)(numBones - 1);
  if ( perBoneWeights )
  {
    v10 = 0i64;
    if ( v8 >= 0 )
    {
      p_m_rotation = &poseLocalSpaceOutAcc->m_rotation;
      v12 = (char *)posePose - (char *)poseLocalSpaceOutAcc;
      do
      {
        v13 = perBoneWeights[v10];
        v14 = *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad + v12);
        ++v10;
        p_m_rotation += 3;
        v6.m128_f32[0] = (float)(v13 * 0.0039215689) * weight;
        v6 = _mm_shuffle_ps(v6, v6, 0);
        p_m_rotation[-2].m_vec.m_quad = _mm_add_ps(
                                          _mm_mul_ps(_mm_sub_ps(v14, p_m_rotation[-2].m_vec.m_quad), v6),
                                          p_m_rotation[-2].m_vec.m_quad);
        p_m_rotation[-4].m_vec.m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_sub_ps(
                                              *(__m128 *)((char *)&p_m_rotation[-4].m_vec.m_quad + v12),
                                              p_m_rotation[-4].m_vec.m_quad),
                                            v6),
                                          p_m_rotation[-4].m_vec.m_quad);
        v15 = _mm_mul_ps(*(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v12), p_m_rotation[-3].m_vec.m_quad);
        v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
        v17 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_xor_ps(
                    (__m128)_mm_slli_epi32(
                              _mm_srli_epi32(
                                (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16), (__m128)0i64),
                                0x1Fu),
                              0x1Fu),
                    v6),
                  *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v12)),
                _mm_mul_ps(_mm_sub_ps(query.m_quad, v6), p_m_rotation[-3].m_vec.m_quad));
        v18 = _mm_mul_ps(v17, v17);
        v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
        v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
        v21 = _mm_rsqrt_ps(v20);
        p_m_rotation[-3].m_vec.m_quad = _mm_mul_ps(
                                          v17,
                                          _mm_mul_ps(
                                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                            _mm_mul_ps(*(__m128 *)_xmm, v21)));
        p_m_rotation[-2] = (hkQuaternionf)_xmm;
      }
      while ( v10 <= v9 );
    }
  }
  else if ( v8 >= 0 )
  {
    v7.m128_f32[0] = weight;
    v22 = (char *)posePose - (char *)poseLocalSpaceOutAcc;
    v23 = &poseLocalSpaceOutAcc->m_rotation;
    v24 = _mm_shuffle_ps(v7, v7, 0);
    v25 = v9 + 1;
    do
    {
      v26 = *(__m128 *)((char *)&v23[1].m_vec.m_quad + v22);
      v23 += 3;
      v23[-2].m_vec.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v26, v23[-2].m_vec.m_quad), v24), v23[-2].m_vec.m_quad);
      v23[-4].m_vec.m_quad = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_sub_ps(*(__m128 *)((char *)&v23[-4].m_vec.m_quad + v22), v23[-4].m_vec.m_quad),
                                 v24),
                               v23[-4].m_vec.m_quad);
      v27 = _mm_mul_ps(*(__m128 *)((char *)&v23[-3].m_vec.m_quad + v22), v23[-3].m_vec.m_quad);
      v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 78), v27);
      v29 = _mm_add_ps(
              _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v28, v28, 177), v28), (__m128)0i64),
                              0x1Fu),
                            0x1Fu),
                  v24),
                *(__m128 *)((char *)&v23[-3].m_vec.m_quad + v22)),
              _mm_mul_ps(_mm_sub_ps(query.m_quad, v24), v23[-3].m_vec.m_quad));
      v30 = _mm_mul_ps(v29, v29);
      v31 = _mm_add_ps(_mm_shuffle_ps(v30, v30, 78), v30);
      v32 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 177), v31);
      v33 = _mm_rsqrt_ps(v32);
      v23[-3].m_vec.m_quad = _mm_mul_ps(
                               v29,
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v33, v32), v33)),
                                 _mm_mul_ps(*(__m128 *)_xmm, v33)));
      v23[-2] = (hkQuaternionf)_xmm;
      --v25;
    }
    while ( v25 );
  }
  hkQsTransform_fasterRenormalizeBatch(poseLocalSpaceOutAcc, numBones);
}

// File Line: 827
// RVA: 0x1BA660
void __fastcall SkeletalPose::Blend(
        SkeletalPose *this,
        SkeletalPose *inputPose,
        float weight,
        unsigned int boneCountMaxLOD,
        bool applyAllTransforms,
        float *weightset_array)
{
  __m128 v6; // xmm7
  hkQsTransformf *m_data; // rbx
  hkQsTransformf *v11; // r10
  unsigned int m_size; // r9d
  hkQuaternionf *p_m_rotation; // rax
  signed __int64 v14; // rbx
  __int64 v15; // rcx
  hkQuaternionf v16; // xmm0
  hkaSkeleton *mhkaSkeleton; // r11
  signed __int64 v18; // rbx
  hkQuaternionf *v19; // rdx
  __int64 v20; // r15
  __int64 v21; // r10
  __int64 v22; // r8
  hkQuaternionf v23; // xmm0
  hkQuaternionf v24; // xmm1
  UFG::qVector4 v25; // xmm1
  UFG::qVector4 v26; // xmm0
  UFG::qVector4 v27; // xmm1
  Render::DebugDrawContext *Context; // rax
  UFG::TransformNodeComponent *m_pPointer; // rcx
  UFG::qVector4 v30; // xmm1
  UFG::qVector4 v31; // xmm0
  UFG::qVector4 v32; // xmm1
  Render::DebugDrawContext *v33; // rax
  hkQsTransformf *v34; // r12
  hkQsTransformf *v35; // r15
  unsigned int v36; // ebx
  hkaSkeleton *v37; // r9
  __int64 v38; // rcx
  __int64 v39; // rdx
  __int64 v40; // r8
  UFG::qVector4 v41; // xmm1
  UFG::qVector4 v42; // xmm0
  UFG::qVector4 v43; // xmm1
  Render::DebugDrawContext *v44; // rax
  UFG::qVector4 m_rotation; // xmm1
  __m128 v46; // xmm7
  UFG::qVector4 m_scale; // xmm0
  __m128 v48; // xmm6
  __m128 v49; // xmm0
  __m128 v50; // xmm5
  __m128 v51; // xmm0
  __m128 v52; // xmm1
  __m128 v53; // xmm0
  __m128 v54; // xmm4
  __m128 v55; // xmm4
  __m128 v56; // xmm0
  __m128 v57; // xmm2
  __m128 v58; // xmm1
  __m128 v59; // xmm2
  UFG::TransformNodeComponent *v60; // rcx
  UFG::qMatrix44 xform; // [rsp+18h] [rbp-69h] BYREF
  hkTransformf transform; // [rsp+58h] [rbp-29h] BYREF
  char v63; // [rsp+F8h] [rbp+77h]
  float *perBoneWeights; // [rsp+100h] [rbp+7Fh]

  if ( weight == 1.0 )
  {
    m_data = hkaPose::getSyncedPoseLocalSpace(inputPose->mHavokPose)->m_data;
    v11 = hkaPose::accessUnsyncedPoseLocalSpace(this->mHavokPose)->m_data;
    m_size = inputPose->mHavokPose->m_skeleton->m_bones.m_size;
    if ( (boneCountMaxLOD & 0x80000000) == 0 && boneCountMaxLOD < m_size )
      m_size = boneCountMaxLOD;
    if ( v63 )
    {
      if ( m_size )
      {
        p_m_rotation = &v11->m_rotation;
        v14 = (char *)m_data - (char *)v11;
        v15 = m_size;
        do
        {
          v16.m_vec.m_quad = *(__m128 *)((char *)&p_m_rotation[-1] + v14);
          p_m_rotation += 3;
          p_m_rotation[-4] = (hkQuaternionf)v16.m_vec.m_quad;
          p_m_rotation[-3] = *(hkQuaternionf *)((char *)p_m_rotation + v14 - 48);
          p_m_rotation[-2] = *(hkQuaternionf *)((char *)p_m_rotation + v14 - 32);
          --v15;
        }
        while ( v15 );
      }
    }
    else
    {
      mhkaSkeleton = this->mRigHandle.mUFGSkeleton->mhkaSkeleton;
      if ( m_size )
      {
        v18 = (char *)m_data - (char *)v11;
        v19 = &v11->m_rotation;
        v20 = -16i64 - (_QWORD)v11;
        v21 = m_size;
        v22 = 0i64;
        do
        {
          if ( mhkaSkeleton->m_bones.m_data[v22].m_lockTranslation.m_bool )
            v23.m_vec.m_quad = *(__m128 *)((char *)&mhkaSkeleton->m_referencePose.m_data->m_translation
                                         + v20
                                         + (unsigned __int64)v19);
          else
            v23.m_vec.m_quad = *(__m128 *)((char *)&v19[-1] + v18);
          v19[-1] = (hkQuaternionf)v23.m_vec.m_quad;
          v24.m_vec.m_quad = *(__m128 *)((char *)v19 + v18);
          v19 += 3;
          ++v22;
          v19[-3] = (hkQuaternionf)v24.m_vec.m_quad;
          v19[-2] = *(hkQuaternionf *)((char *)v19 + v18 - 32);
          --v21;
        }
        while ( v21 );
      }
    }
    if ( sShowCoordBefore )
    {
      SkeletalPose::syncTransformToRoot(this);
      v25 = this->mRootMatrix44.v1;
      xform.v0 = this->mRootMatrix44.v0;
      v26 = this->mRootMatrix44.v2;
      xform.v1 = v25;
      v27 = this->mRootMatrix44.v3;
      xform.v2 = v26;
      xform.v3 = v27;
      Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              1u);
      Render::DebugDrawContext::DrawCoord(Context, &xform, 0.25, 0i64);
    }
    SkeletalPose::syncTransformToRoot(inputPose);
    if ( inputPose->mIsRootDirty )
    {
      hkTransformf::set4x4ColumnMajor(&transform, &inputPose->mRootMatrix44.v0.x);
      hkQsTransformf::setFromTransformNoScale(&inputPose->mRootQsMatrix, &transform);
      inputPose->mIsRootDirty = 0;
    }
    this->mRootQsMatrix.m_translation = inputPose->mRootQsMatrix.m_translation;
    this->mRootQsMatrix.m_rotation = inputPose->mRootQsMatrix.m_rotation;
    this->mRootQsMatrix.m_scale = inputPose->mRootQsMatrix.m_scale;
    hkQsTransformf::get4x4ColumnMajor(&inputPose->mRootQsMatrix, &this->mRootMatrix44.v0.x);
    m_pPointer = (UFG::TransformNodeComponent *)this->mRootTransformNode.m_pPointer;
    this->mIsRootDirty = 0;
    if ( m_pPointer )
      UFG::TransformNodeComponent::SetWorldTransform(m_pPointer, &this->mRootMatrix44);
    if ( sShowCoordAfter )
    {
      SkeletalPose::syncTransformToRoot(this);
      v30 = this->mRootMatrix44.v1;
      xform.v0 = this->mRootMatrix44.v0;
      v31 = this->mRootMatrix44.v2;
      xform.v1 = v30;
      v32 = this->mRootMatrix44.v3;
      xform.v2 = v31;
      xform.v3 = v32;
      v33 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      Render::DebugDrawContext::DrawCoord(v33, &xform, 0.25, 0i64);
    }
  }
  else if ( weight > 0.0 )
  {
    v34 = hkaPose::getSyncedPoseLocalSpace(inputPose->mHavokPose)->m_data;
    v35 = hkaPose::accessUnsyncedPoseLocalSpace(this->mHavokPose)->m_data;
    v36 = inputPose->mHavokPose->m_skeleton->m_bones.m_size;
    if ( (boneCountMaxLOD & 0x80000000) == 0 && boneCountMaxLOD < v36 )
      v36 = boneCountMaxLOD;
    blendPosehkQ(v35, v34, v36, weight, perBoneWeights, 0i64);
    if ( !v63 )
    {
      v37 = this->mRigHandle.mUFGSkeleton->mhkaSkeleton;
      if ( v36 )
      {
        v38 = 0i64;
        v39 = 0i64;
        v40 = v36;
        do
        {
          if ( v37->m_bones.m_data[v39].m_lockTranslation.m_bool )
            v35[v38].m_translation = v37->m_referencePose.m_data[v38].m_translation;
          ++v39;
          ++v38;
          --v40;
        }
        while ( v40 );
      }
    }
    if ( sShowCoordBefore )
    {
      SkeletalPose::syncTransformToRoot(this);
      v41 = this->mRootMatrix44.v1;
      transform.m_rotation.m_col0 = (hkVector4f)this->mRootMatrix44.v0;
      v42 = this->mRootMatrix44.v2;
      transform.m_rotation.m_col1 = (hkVector4f)v41;
      v43 = this->mRootMatrix44.v3;
      transform.m_rotation.m_col2 = (hkVector4f)v42;
      transform.m_translation = (hkVector4f)v43;
      v44 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      Render::DebugDrawContext::DrawCoord(v44, (UFG::qMatrix44 *)&transform, 0.25, 0i64);
    }
    SkeletalPose::syncTransformToRoot(this);
    if ( this->mIsRootDirty )
    {
      hkTransformf::set4x4ColumnMajor(&transform, &this->mRootMatrix44.v0.x);
      hkQsTransformf::setFromTransformNoScale(&this->mRootQsMatrix, &transform);
      this->mIsRootDirty = 0;
    }
    m_rotation = (UFG::qVector4)this->mRootQsMatrix.m_rotation;
    v6.m128_f32[0] = weight;
    v46 = _mm_shuffle_ps(v6, v6, 0);
    xform.v0 = (UFG::qVector4)this->mRootQsMatrix.m_translation;
    m_scale = (UFG::qVector4)this->mRootQsMatrix.m_scale;
    xform.v1 = m_rotation;
    xform.v2 = m_scale;
    SkeletalPose::syncTransformToRoot(inputPose);
    if ( inputPose->mIsRootDirty )
    {
      hkTransformf::set4x4ColumnMajor(&transform, &inputPose->mRootMatrix44.v0.x);
      hkQsTransformf::setFromTransformNoScale(&inputPose->mRootQsMatrix, &transform);
      inputPose->mIsRootDirty = 0;
    }
    v48 = _mm_add_ps(
            (__m128)xform.v2,
            _mm_mul_ps(_mm_sub_ps(inputPose->mRootQsMatrix.m_scale.m_quad, (__m128)xform.v2), v46));
    v49 = _mm_sub_ps(inputPose->mRootQsMatrix.m_translation.m_quad, (__m128)xform.v0);
    xform.v2 = (UFG::qVector4)v48;
    v50 = _mm_add_ps((__m128)xform.v0, _mm_mul_ps(v49, v46));
    v51 = _mm_mul_ps((__m128)xform.v1, inputPose->mRootQsMatrix.m_rotation.m_vec.m_quad);
    xform.v0 = (UFG::qVector4)v50;
    v52 = _mm_add_ps(_mm_shuffle_ps(v51, v51, 78), v51);
    v53 = _mm_mul_ps(_mm_sub_ps(query.m_quad, v46), (__m128)xform.v1);
    v54 = _mm_mul_ps(
            _mm_xor_ps(
              (__m128)_mm_slli_epi32(
                        _mm_srli_epi32(
                          (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v52, v52, 177), v52), (__m128)0i64),
                          0x1Fu),
                        0x1Fu),
              v46),
            inputPose->mRootQsMatrix.m_rotation.m_vec.m_quad);
    this->mRootQsMatrix.m_translation.m_quad = v50;
    this->mRootQsMatrix.m_scale.m_quad = v48;
    v55 = _mm_add_ps(v54, v53);
    v56 = _mm_mul_ps(v55, v55);
    v57 = _mm_add_ps(_mm_shuffle_ps(v56, v56, 78), v56);
    v58 = _mm_add_ps(_mm_shuffle_ps(v57, v57, 177), v57);
    v59 = _mm_rsqrt_ps(v58);
    xform.v1 = (UFG::qVector4)_mm_mul_ps(
                                v55,
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v59, v58), v59)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v59)));
    this->mRootQsMatrix.m_rotation = (hkQuaternionf)xform.v1;
    hkQsTransformf::get4x4ColumnMajor((hkQsTransformf *)&xform, &this->mRootMatrix44.v0.x);
    v60 = (UFG::TransformNodeComponent *)this->mRootTransformNode.m_pPointer;
    this->mIsRootDirty = 0;
    if ( v60 )
      UFG::TransformNodeComponent::SetWorldTransform(v60, &this->mRootMatrix44);
  }
}

// File Line: 935
// RVA: 0x1BC1D0
void __fastcall SkeletalPose::RigLoadedCallback(UFG::RigHandle *handle, _QWORD *userData)
{
  UFG::qResourceData *mData; // rsi
  __int64 v3; // rbx
  char v4; // di
  char v5; // cl
  _QWORD **Value; // rax
  __int64 v7; // rax
  _DWORD *v8; // r14
  int v9; // edi
  int v10; // ebp
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  int v14; // eax
  int v15; // eax
  int v16; // r9d
  int v17; // eax
  int v18; // eax
  int v19; // r9d
  int v20; // ebp
  int v21; // r9d
  int v22; // eax
  int v23; // eax
  int v24; // r9d
  int v25; // edx
  _DWORD *v26; // rdi
  __int64 v27; // rcx
  char v28; // al
  hkResult v29; // [rsp+30h] [rbp-78h] BYREF
  hkResult v30; // [rsp+34h] [rbp-74h] BYREF
  hkResult v31; // [rsp+38h] [rbp-70h] BYREF
  hkResult v32; // [rsp+3Ch] [rbp-6Ch] BYREF
  hkResult v33; // [rsp+40h] [rbp-68h] BYREF
  __int64 v34; // [rsp+48h] [rbp-60h]
  __int64 v35; // [rsp+50h] [rbp-58h]
  hkResult result; // [rsp+B0h] [rbp+8h] BYREF
  _QWORD *v37; // [rsp+B8h] [rbp+10h]
  hkResult v38; // [rsp+C0h] [rbp+18h] BYREF
  hkResult v39; // [rsp+C8h] [rbp+20h] BYREF

  v37 = userData;
  v34 = -2i64;
  mData = handle->mData;
  v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v4 = ++*(_BYTE *)(v3 + 80);
  *(_DWORD *)(v3 + 4i64 * v4) = 2;
  *(_QWORD *)(v3 + 8i64 * v4 + 16) = "hkaPose";
  *(_QWORD *)(v3 + 8i64 * v4 + 48) = 0i64;
  v5 = *(_BYTE *)(v3 + 81);
  if ( v4 > v5 )
    v5 = v4;
  *(_BYTE *)(v3 + 81) = v5;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  v8 = (_DWORD *)v7;
  v35 = v7;
  if ( v7 )
  {
    *(_QWORD *)v7 = mData[3].mNode.mParent->mChild[0];
    *(_QWORD *)(v7 + 8) = 0i64;
    *(_DWORD *)(v7 + 16) = 0;
    *(_DWORD *)(v7 + 20) = 0x80000000;
    *(_QWORD *)(v7 + 24) = 0i64;
    *(_DWORD *)(v7 + 32) = 0;
    *(_DWORD *)(v7 + 36) = 0x80000000;
    *(_QWORD *)(v7 + 40) = 0i64;
    *(_DWORD *)(v7 + 48) = 0;
    *(_DWORD *)(v7 + 52) = 0x80000000;
    *(_WORD *)(v7 + 56) = 0;
    *(_QWORD *)(v7 + 64) = 0i64;
    *(_DWORD *)(v7 + 72) = 0;
    *(_DWORD *)(v7 + 76) = 0x80000000;
    v9 = *(_DWORD *)(*(_QWORD *)v7 + 48i64);
    v10 = (v9 + 3) & 0xFFFFFFFC;
    if ( (*(_DWORD *)(v7 + 36) & 0x3FFFFFFF) >= v10 )
      result.m_enum = HK_SUCCESS;
    else
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (void *)(v7 + 24), v10, 48);
    if ( (v8[5] & 0x3FFFFFFF) >= v10 )
      v38.m_enum = HK_SUCCESS;
    else
      hkArrayUtil::_reserve(&v38, &hkContainerHeapAllocator::s_alloc, v8 + 2, v10, 48);
    if ( (v8[13] & 0x3FFFFFFF) >= v10 )
      v39.m_enum = HK_SUCCESS;
    else
      hkArrayUtil::_reserve(&v39, &hkContainerHeapAllocator::s_alloc, v8 + 10, v10, 4);
    v11 = v8[9] & 0x3FFFFFFF;
    if ( v11 >= v9 )
    {
      v29.m_enum = HK_SUCCESS;
    }
    else
    {
      v12 = 2 * v11;
      v13 = v9;
      if ( v9 < v12 )
        v13 = v12;
      hkArrayUtil::_reserve(&v29, &hkContainerHeapAllocator::s_alloc, v8 + 6, v13, 48);
    }
    v8[8] = v9;
    v14 = v8[5] & 0x3FFFFFFF;
    if ( v14 >= v9 )
    {
      v30.m_enum = HK_SUCCESS;
    }
    else
    {
      v15 = 2 * v14;
      v16 = v9;
      if ( v9 < v15 )
        v16 = v15;
      hkArrayUtil::_reserve(&v30, &hkContainerHeapAllocator::s_alloc, v8 + 2, v16, 48);
    }
    v8[4] = v9;
    v17 = v8[13] & 0x3FFFFFFF;
    if ( v17 >= v9 )
    {
      v31.m_enum = HK_SUCCESS;
    }
    else
    {
      v18 = 2 * v17;
      v19 = v9;
      if ( v9 < v18 )
        v19 = v18;
      hkArrayUtil::_reserve(&v31, &hkContainerHeapAllocator::s_alloc, v8 + 10, v19, 4);
    }
    v8[12] = v9;
    v20 = *(_DWORD *)(*(_QWORD *)v8 + 96i64);
    v21 = (v20 + 3) & 0xFFFFFFFC;
    if ( (v8[19] & 0x3FFFFFFF) >= v21 )
      v32.m_enum = HK_SUCCESS;
    else
      hkArrayUtil::_reserve(&v32, &hkContainerHeapAllocator::s_alloc, v8 + 16, v21, 4);
    v22 = v8[19] & 0x3FFFFFFF;
    if ( v22 >= v20 )
    {
      v33.m_enum = HK_SUCCESS;
    }
    else
    {
      v23 = 2 * v22;
      v24 = v20;
      if ( v20 < v23 )
        v24 = v23;
      hkArrayUtil::_reserve(&v33, &hkContainerHeapAllocator::s_alloc, v8 + 16, v24, 4);
    }
    v25 = v20 - v8[18];
    v26 = (_DWORD *)(*((_QWORD *)v8 + 8) + 4i64 * (int)v8[18]);
    v27 = v25;
    if ( v25 > 0 )
    {
      while ( v27 )
      {
        *v26++ = 0;
        --v27;
      }
    }
    v8[18] = v20;
  }
  else
  {
    v8 = 0i64;
  }
  v37[31] = v8;
  v28 = *(_BYTE *)(v3 + 80);
  if ( v28 > 0 )
  {
    *(_BYTE *)(v3 + 80) = v28 - 1;
  }
  else
  {
    *(_BYTE *)(v3 + 80) = 0;
    *(_DWORD *)v3 = 3;
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_QWORD *)(v3 + 48) = 0i64;
  }
}

// File Line: 946
// RVA: 0x1BC540
void __fastcall SkeletalPose::RigUnloadedCallback(UFG::RigHandle *handle, void *userData)
{
  __int64 v2; // rdi
  _QWORD **Value; // rax

  v2 = *((_QWORD *)userData + 31);
  if ( v2 )
  {
    hkaPose::~hkaPose(*((hkaPose **)userData + 31));
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, __int64, __int64))(*Value[11] + 16i64))(Value[11], v2, 80i64);
    *((_QWORD *)userData + 31) = 0i64;
  }
  else
  {
    *((_QWORD *)userData + 31) = 0i64;
  }
}

// File Line: 955
// RVA: 0x1BB210
void __fastcall DrawBoneHavok(
        hkaSkeleton *skeleton,
        hkQsTransformf *poseModelSpace,
        hkQsTransformf *worldFromModel,
        const bool *boneDraw,
        UFG::qColour *colour)
{
  Render::DebugDrawContext *Context; // rax
  int m_size; // edi
  hkVector4f v10; // xmm1
  __int16 v11; // bx
  __int64 v12; // rdi
  const bool *v13; // r15
  __int64 v14; // r12
  hkQsTransformf *v15; // r14
  __int16 v16; // cx
  __m128 m_quad; // xmm8
  hkQuaternionf v18; // xmm6
  __m128 v19; // xmm7
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm5
  __m128 v24; // xmm2
  __m128 v25; // xmm4
  __m128 v26; // xmm4
  __m128 v27; // xmm8
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  Render::DebugDrawContext *v33; // rax
  const char *v34; // r8
  UFG::qVector3 world_position; // [rsp+30h] [rbp-D0h] BYREF
  UFG::qStringBuilder v36; // [rsp+40h] [rbp-C0h] BYREF
  Render::DebugDrawContext *v37; // [rsp+50h] [rbp-B0h]
  hkVector4f v38; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qVector3 line_points; // [rsp+70h] [rbp-90h] BYREF
  unsigned __int64 v40; // [rsp+7Ch] [rbp-84h]
  int v41; // [rsp+84h] [rbp-7Ch]
  hkVector4f v42; // [rsp+90h] [rbp-70h] BYREF
  UFG::qStringBuilder v43; // [rsp+A0h] [rbp-60h] BYREF
  UFG::qStringBuilder v44; // [rsp+B0h] [rbp-50h] BYREF
  UFG::qStringBuilder v45; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v46; // [rsp+D0h] [rbp-30h]
  hkQsTransformf v47; // [rsp+E0h] [rbp-20h] BYREF
  UFG::qMatrix44 d; // [rsp+110h] [rbp+10h] BYREF
  __int16 v49; // [rsp+1C0h] [rbp+C0h]

  v46 = -2i64;
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v37 = Context;
  m_size = skeleton->m_bones.m_size;
  v49 = m_size;
  if ( gDrawSkeletonName )
  {
    v10.m_quad = (__m128)worldFromModel->m_translation;
    LODWORD(world_position.x) = worldFromModel->m_translation;
    LODWORD(world_position.y) = _mm_shuffle_ps(v10.m_quad, v10.m_quad, 85).m128_u32[0];
    LODWORD(world_position.z) = worldFromModel->m_translation.m_quad.m128_i32[2];
    Render::DebugDrawContext::DrawText(
      Context,
      &world_position,
      colour,
      (const char *)((unsigned __int64)skeleton->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
  }
  v11 = 0;
  if ( (__int16)m_size > 0 )
  {
    v12 = 0i64;
    v13 = boneDraw;
    v14 = 0i64;
    v15 = poseModelSpace;
    do
    {
      hkVector4f::setTransformedPos(&v42, worldFromModel, &v15->m_translation);
      v16 = skeleton->m_parentIndices.m_data[v14];
      if ( v16 == -1 )
      {
        v38.m_quad = 0i64;
      }
      else
      {
        hkVector4f::setTransformedPos(&v38, worldFromModel, &poseModelSpace[v16].m_translation);
        *(_QWORD *)&line_points.x = v42.m_quad.m128_u64[0];
        LODWORD(line_points.z) = v42.m_quad.m128_i32[2];
        v40 = v38.m_quad.m128_u64[0];
        v41 = v38.m_quad.m128_i32[2];
        Render::DebugDrawContext::DrawLineStrip(
          v37,
          &line_points,
          2,
          colour,
          &UFG::qMatrix44::msIdentity,
          (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback);
      }
      if ( sShowCoords && boneDraw )
      {
        if ( gDrawSkeletonBoneNameFilter.mLength )
        {
          if ( (unsigned int)UFG::qWildcardMatchInsensitive(
                               gDrawSkeletonBoneNameFilter.mData,
                               (char *)((unsigned __int64)skeleton->m_bones.m_data[v12].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
            goto LABEL_15;
        }
        else if ( gDrawSkeletonBoneIDFilter < 0 || gDrawSkeletonBoneIDFilter == v11 )
        {
LABEL_15:
          if ( *v13 || gDrawSkeletonAllCoords || gDrawSkeletonBoneNames || gDrawSkeletonBoneTranslationLockInfo )
          {
            m_quad = v15->m_rotation.m_vec.m_quad;
            v18.m_vec.m_quad = (__m128)worldFromModel->m_rotation;
            v19 = _mm_shuffle_ps(v18.m_vec.m_quad, v18.m_vec.m_quad, 255);
            v20 = _mm_mul_ps(v15->m_translation.m_quad, v18.m_vec.m_quad);
            v21 = _mm_mul_ps(
                    v18.m_vec.m_quad,
                    _mm_add_ps(
                      _mm_shuffle_ps(v20, v20, 170),
                      _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0))));
            v22 = _mm_sub_ps(
                    _mm_mul_ps(
                      v18.m_vec.m_quad,
                      _mm_shuffle_ps(v15->m_translation.m_quad, v15->m_translation.m_quad, 201)),
                    _mm_mul_ps(v15->m_translation.m_quad, _mm_shuffle_ps(v18.m_vec.m_quad, v18.m_vec.m_quad, 201)));
            v23 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(v15->m_translation.m_quad, _mm_sub_ps(_mm_mul_ps(v19, v19), (__m128)xmmword_141A711B0)),
                      v21),
                    _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v19));
            v47.m_translation.m_quad = _mm_add_ps(_mm_add_ps(v23, v23), worldFromModel->m_translation.m_quad);
            v24 = _mm_shuffle_ps(m_quad, m_quad, 255);
            v25 = _mm_sub_ps(
                    _mm_mul_ps(v18.m_vec.m_quad, _mm_shuffle_ps(m_quad, m_quad, 201)),
                    _mm_mul_ps(m_quad, _mm_shuffle_ps(v18.m_vec.m_quad, v18.m_vec.m_quad, 201)));
            v26 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v25, v25, 201), _mm_mul_ps(m_quad, v19)),
                    _mm_mul_ps(v18.m_vec.m_quad, v24));
            v27 = _mm_mul_ps(m_quad, v18.m_vec.m_quad);
            v28 = _mm_shuffle_ps(
                    v26,
                    _mm_unpackhi_ps(
                      v26,
                      _mm_sub_ps(
                        _mm_mul_ps(v24, v19),
                        _mm_add_ps(
                          _mm_shuffle_ps(v27, v27, 170),
                          _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0))))),
                    196);
            v47.m_scale.m_quad = _mm_mul_ps(worldFromModel->m_scale.m_quad, v15->m_scale.m_quad);
            v29 = _mm_mul_ps(v28, v28);
            v30 = _mm_add_ps(v29, _mm_shuffle_ps(v29, v29, 78));
            v31 = _mm_add_ps(_mm_shuffle_ps(v30, v30, 177), v30);
            v32 = _mm_rsqrt_ps(v31);
            v47.m_rotation.m_vec.m_quad = _mm_mul_ps(
                                            v28,
                                            _mm_mul_ps(
                                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
                                              _mm_mul_ps(v32, *(__m128 *)_xmm)));
            hkQsTransformf::get4x4ColumnMajor(&v47, &d.v0.x);
            world_position.x = d.v3.x;
            world_position.y = d.v3.y;
            world_position.z = d.v3.z;
            if ( *v13 || gDrawSkeletonAllCoords )
            {
              v33 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                  Render::DebugDrawManager::mInstance,
                                                  1u);
              Render::DebugDrawContext::DrawCoord(v33, &d, gDrawSkeletonAllCoordsScale, 0i64);
            }
            if ( gDrawSkeletonBoneNames
              || gDrawSkeletonBoneTranslationLockInfo
              || gDrawSkeletonBonePosition
              || gDrawSkeletonBoneNormalityInfo )
            {
              UFG::qStringBuilder::qStringBuilder(&v36);
              if ( gDrawSkeletonBoneNames )
              {
                UFG::qStringBuilder::qStringBuilder(&v45);
                UFG::qStringBuilder::Format(
                  &v45,
                  ":%s:%d",
                  (const char *)((unsigned __int64)skeleton->m_bones.m_data[v12].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                  (unsigned int)v11);
                UFG::qStringBuilder::Add(&v36, v45.mBuffer, -1);
                UFG::qStringBuilder::~qStringBuilder(&v45);
              }
              if ( gDrawSkeletonBoneTranslationLockInfo )
              {
                UFG::qStringBuilder::qStringBuilder(&v44);
                v34 = "U";
                if ( skeleton->m_bones.m_data[v12].m_lockTranslation.m_bool )
                  v34 = "L";
                UFG::qStringBuilder::Format(&v44, ":%s", v34);
                UFG::qStringBuilder::Add(&v36, v44.mBuffer, -1);
                UFG::qStringBuilder::~qStringBuilder(&v44);
              }
              if ( gDrawSkeletonBonePosition )
              {
                UFG::qStringBuilder::qStringBuilder(&v43);
                UFG::qStringBuilder::Format(
                  &v43,
                  ":P[%0.4f,%0.4f,%0.4f]",
                  world_position.x,
                  world_position.y,
                  world_position.z);
                UFG::qStringBuilder::Add(&v36, v43.mBuffer, -1);
                UFG::qStringBuilder::~qStringBuilder(&v43);
              }
              Render::DebugDrawContext::DrawText(v37, &world_position, &UFG::qColour::Green, v36.mBuffer);
              UFG::qStringBuilder::~qStringBuilder(&v36);
            }
          }
        }
      }
      ++v11;
      ++v14;
      ++v15;
      ++v13;
      ++v12;
    }
    while ( v11 < v49 );
  }
}

