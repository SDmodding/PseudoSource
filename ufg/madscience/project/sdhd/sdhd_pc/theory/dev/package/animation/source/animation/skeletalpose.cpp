// File Line: 41
// RVA: 0x146AC00
__int64 dynamic_initializer_for__gDrawSkeletonBoneNameFilter__()
{
  UFG::qString::qString(&gDrawSkeletonBoneNameFilter);
  return atexit(dynamic_atexit_destructor_for__gDrawSkeletonBoneNameFilter__);
}

// File Line: 46
// RVA: 0x146AD80
__int64 dynamic_initializer_for__s_uDirectionUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Direction", 0xFFFFFFFF);
  s_uDirectionUID_0 = result;
  return result;
}

// File Line: 47
// RVA: 0x146ADA0
__int64 dynamic_initializer_for__s_uSync01UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Sync01", 0xFFFFFFFF);
  s_uSync01UID_0 = result;
  return result;
}

// File Line: 48
// RVA: 0x146ACE0
__int64 dynamic_initializer_for__s_uBalanceUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Balance", 0xFFFFFFFF);
  s_uBalanceUID_0 = result;
  return result;
}

// File Line: 50
// RVA: 0x146AD40
__int64 dynamic_initializer_for__s_uBip01_R_ClavicleUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R Clavicle", 0xFFFFFFFF);
  s_uBip01_R_ClavicleUID_0 = result;
  return result;
}

// File Line: 51
// RVA: 0x146AD60
__int64 dynamic_initializer_for__s_uBip01_R_UpperArmUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R UpperArm", 0xFFFFFFFF);
  s_uBip01_R_UpperArmUID_0 = result;
  return result;
}

// File Line: 52
// RVA: 0x146AE20
__int64 dynamic_initializer_for__s_ur_upperarm_twistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("r_upperarm_twist", 0xFFFFFFFF);
  s_ur_upperarm_twistUID_0 = result;
  return result;
}

// File Line: 53
// RVA: 0x146AE00
__int64 dynamic_initializer_for__s_ur_shoulder_jointUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("r_shoulder_joint", 0xFFFFFFFF);
  s_ur_shoulder_jointUID_0 = result;
  return result;
}

// File Line: 55
// RVA: 0x146AD00
__int64 dynamic_initializer_for__s_uBip01_L_ClavicleUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L Clavicle", 0xFFFFFFFF);
  s_uBip01_L_ClavicleUID_0 = result;
  return result;
}

// File Line: 56
// RVA: 0x146AD20
__int64 dynamic_initializer_for__s_uBip01_L_UpperArmUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L UpperArm", 0xFFFFFFFF);
  s_uBip01_L_UpperArmUID_0 = result;
  return result;
}

// File Line: 57
// RVA: 0x146ADE0
__int64 dynamic_initializer_for__s_ul_upperarm_twistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("l_upperarm_twist", 0xFFFFFFFF);
  s_ul_upperarm_twistUID_0 = result;
  return result;
}

// File Line: 58
// RVA: 0x146ADC0
__int64 dynamic_initializer_for__s_ul_shoulder_jointUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("l_shoulder_joint", 0xFFFFFFFF);
  s_ul_shoulder_jointUID_0 = result;
  return result;
}

// File Line: 60
// RVA: 0x146ACA0
__int64 dynamic_initializer_for__s_R_Forearm_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R Forearm", 0xFFFFFFFF);
  s_R_Forearm_UID_0 = result;
  return result;
}

// File Line: 61
// RVA: 0x146ACC0
__int64 dynamic_initializer_for__s_R_Hand_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R Hand", 0xFFFFFFFF);
  s_R_Hand_UID_0 = result;
  return result;
}

// File Line: 62
// RVA: 0x146AC80
__int64 dynamic_initializer_for__s_R_ForeTwist_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R ForeTwist", 0xFFFFFFFF);
  s_R_ForeTwist_UID_0 = result;
  return result;
}

// File Line: 64
// RVA: 0x146AC40
__int64 dynamic_initializer_for__s_L_Forearm_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L Forearm", 0xFFFFFFFF);
  s_L_Forearm_UID_0 = result;
  return result;
}

// File Line: 65
// RVA: 0x146AC60
__int64 dynamic_initializer_for__s_L_Hand_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L Hand", 0xFFFFFFFF);
  s_L_Hand_UID_0 = result;
  return result;
}

// File Line: 66
// RVA: 0x146AC20
__int64 dynamic_initializer_for__s_L_ForeTwist_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L ForeTwist", 0xFFFFFFFF);
  s_L_ForeTwist_UID_0 = result;
  return result;
}

// File Line: 74
// RVA: 0x1B9500
void __fastcall SkeletalPose::SkeletalPose(SkeletalPose *this, unsigned int rigUid)
{
  unsigned int v2; // ebx
  SkeletalPose *v3; // r14
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v4; // rax
  UFG::RigHandle *v5; // rdi
  __m128 v6; // xmm3
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax
  UFG::qResourceData *v9; // rdi
  signed __int64 v10; // rsi
  char v11; // dl
  __int64 v12; // rax
  char v13; // cl
  _QWORD **v14; // rax
  __int64 v15; // rax
  hkaPose *v16; // r15
  int v17; // edi
  int v18; // ebp
  int v19; // eax
  int v20; // eax
  int v21; // er9
  int v22; // eax
  int v23; // eax
  int v24; // er9
  int v25; // eax
  int v26; // eax
  int v27; // er9
  int v28; // ebp
  int v29; // er9
  int v30; // eax
  int v31; // eax
  int v32; // er9
  int v33; // edx
  float *v34; // rdi
  __int64 v35; // rcx
  char v36; // al
  hkResult v37; // [rsp+30h] [rbp-68h]
  hkResult v38; // [rsp+34h] [rbp-64h]
  hkResult v39; // [rsp+38h] [rbp-60h]
  hkResult v40; // [rsp+3Ch] [rbp-5Ch]
  hkResult v41; // [rsp+40h] [rbp-58h]
  hkResult v42; // [rsp+44h] [rbp-54h]
  __int64 v43; // [rsp+48h] [rbp-50h]
  __int64 v44; // [rsp+50h] [rbp-48h]
  UFG::RigHandle *result; // [rsp+B0h] [rbp+18h]
  hkResult v46; // [rsp+B8h] [rbp+20h]

  v43 = -2i64;
  v2 = rigUid;
  v3 = this;
  v4 = &this->mRootTransformNode;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->mRootTransformNode.m_pPointer = 0i64;
  v5 = &this->mRigHandle;
  result = &this->mRigHandle;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mRigHandle.mPrev);
  v5->mLoadFunction = 0i64;
  v5->mUnloadFunction = 0i64;
  v5->mUserData = 0i64;
  v5->mUFGSkeleton = 0i64;
  v6 = 0i64;
  v3->mRootQsMatrix.m_translation = 0i64;
  v3->mRootQsMatrix.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  v3->mRootQsMatrix.m_scale = (hkVector4f)query.m_quad;
  v6.m128_f32[0] = (float)1;
  v3->mRootMatrix44.v0 = (UFG::qVector4)v6;
  v3->mRootMatrix44.v1 = (UFG::qVector4)_mm_shuffle_ps(v6, v6, 81);
  v3->mRootMatrix44.v2 = (UFG::qVector4)_mm_shuffle_ps(v6, v6, 69);
  v3->mRootMatrix44.v3 = (UFG::qVector4)_mm_shuffle_ps(v6, v6, 21);
  v3->mIsRootDirty = 0;
  v3->mCachedTransformChangeID = -1;
  v7 = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v7 = UFG::qResourceWarehouse::GetInventory(v8, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = v7;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v5->mPrev, 0x39BC0A7Eu, v2, v7);
  v3->mRigHandle.mUnloadFunction = SkeletalPose::RigUnloadedCallback;
  v3->mRigHandle.mLoadFunction = SkeletalPose::RigLoadedCallback;
  v3->mRigHandle.mUserData = v3;
  v9 = v3->mRigHandle.mData;
  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v11 = ++*(_BYTE *)(v10 + 80);
  v12 = v11;
  *(_DWORD *)(v10 + 4 * v12) = 2;
  *(_QWORD *)(v10 + 8 * v12 + 16) = "hkaPose";
  *(_QWORD *)(v10 + 8 * v12 + 48) = 0i64;
  v13 = *(_BYTE *)(v10 + 81);
  if ( v11 > v13 )
    v13 = v11;
  *(_BYTE *)(v10 + 81) = v13;
  v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(v14[11], 80i64);
  v16 = (hkaPose *)v15;
  v44 = v15;
  if ( v15 )
  {
    *(_QWORD *)v15 = v9[3].mNode.mParent->mChild[0];
    *(_QWORD *)(v15 + 8) = 0i64;
    *(_DWORD *)(v15 + 16) = 0;
    *(_DWORD *)(v15 + 20) = 2147483648;
    *(_QWORD *)(v15 + 24) = 0i64;
    *(_DWORD *)(v15 + 32) = 0;
    *(_DWORD *)(v15 + 36) = 2147483648;
    *(_QWORD *)(v15 + 40) = 0i64;
    *(_DWORD *)(v15 + 48) = 0;
    *(_DWORD *)(v15 + 52) = 2147483648;
    *(_WORD *)(v15 + 56) = 0;
    *(_QWORD *)(v15 + 64) = 0i64;
    *(_DWORD *)(v15 + 72) = 0;
    *(_DWORD *)(v15 + 76) = 2147483648;
    v17 = *(_DWORD *)(*(_QWORD *)v15 + 48i64);
    v18 = (v17 + 3) & 0xFFFFFFFC;
    if ( (*(_DWORD *)(v15 + 36) & 0x3FFFFFFF) >= v18 )
      LODWORD(result) = 0;
    else
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (void *)(v15 + 24),
        v18,
        48);
    if ( (v16->m_localPose.m_capacityAndFlags & 0x3FFFFFFF) >= v18 )
      v46.m_enum = 0;
    else
      hkArrayUtil::_reserve(
        &v46,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v16->m_localPose,
        v18,
        48);
    if ( (v16->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) >= v18 )
      v37.m_enum = 0;
    else
      hkArrayUtil::_reserve(
        &v37,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v16->m_boneFlags,
        v18,
        4);
    v19 = v16->m_modelPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v19 >= v17 )
    {
      v38.m_enum = 0;
    }
    else
    {
      v20 = 2 * v19;
      v21 = v17;
      if ( v17 < v20 )
        v21 = v20;
      hkArrayUtil::_reserve(
        &v38,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v16->m_modelPose,
        v21,
        48);
    }
    v16->m_modelPose.m_size = v17;
    v22 = v16->m_localPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v22 >= v17 )
    {
      v39.m_enum = 0;
    }
    else
    {
      v23 = 2 * v22;
      v24 = v17;
      if ( v17 < v23 )
        v24 = v23;
      hkArrayUtil::_reserve(
        &v39,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v16->m_localPose,
        v24,
        48);
    }
    v16->m_localPose.m_size = v17;
    v25 = v16->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v25 >= v17 )
    {
      v40.m_enum = 0;
    }
    else
    {
      v26 = 2 * v25;
      v27 = v17;
      if ( v17 < v26 )
        v27 = v26;
      hkArrayUtil::_reserve(
        &v40,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v16->m_boneFlags,
        v27,
        4);
    }
    v16->m_boneFlags.m_size = v17;
    v28 = v16->m_skeleton->m_floatSlots.m_size;
    v29 = (v28 + 3) & 0xFFFFFFFC;
    if ( (v16->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) >= v29 )
      v41.m_enum = 0;
    else
      hkArrayUtil::_reserve(
        &v41,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v16->m_floatSlotValues,
        v29,
        4);
    v30 = v16->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v30 >= v28 )
    {
      v42.m_enum = 0;
    }
    else
    {
      v31 = 2 * v30;
      v32 = v28;
      if ( v28 < v31 )
        v32 = v31;
      hkArrayUtil::_reserve(
        &v42,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v16->m_floatSlotValues,
        v32,
        4);
    }
    v33 = v28 - v16->m_floatSlotValues.m_size;
    v34 = &v16->m_floatSlotValues.m_data[v16->m_floatSlotValues.m_size];
    v35 = v33;
    if ( v33 > 0 )
    {
      while ( v35 )
      {
        *v34 = 0.0;
        ++v34;
        --v35;
      }
    }
    v16->m_floatSlotValues.m_size = v28;
  }
  else
  {
    v16 = 0i64;
  }
  v3->mHavokPose = v16;
  v36 = *(_BYTE *)(v10 + 80);
  if ( v36 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v36 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  v3->mBoneUpdateCount = -1;
}

// File Line: 96
// RVA: 0x1B9970
void __fastcall SkeletalPose::SkeletalPose(SkeletalPose *this, UFG::RigResource *rig)
{
  UFG::RigResource *v2; // rbx
  SkeletalPose *v3; // r15
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v4; // rax
  UFG::RigHandle *v5; // rdi
  __m128 v6; // xmm3
  unsigned int v7; // esi
  UFG::qResourceInventory *inventory; // rax
  UFG::qResourceWarehouse *v9; // rax
  signed __int64 v10; // rsi
  char v11; // dl
  __int64 v12; // rax
  char v13; // cl
  _QWORD **v14; // rax
  __int64 v15; // rax
  hkaPose *v16; // r14
  int v17; // edi
  int v18; // ebp
  int v19; // eax
  int v20; // eax
  int v21; // er9
  int v22; // eax
  int v23; // eax
  int v24; // er9
  int v25; // eax
  int v26; // eax
  int v27; // er9
  int v28; // ebp
  int v29; // er9
  int v30; // eax
  int v31; // eax
  int v32; // er9
  int v33; // edx
  float *v34; // rdi
  __int64 v35; // rcx
  char v36; // al
  hkResult v37; // [rsp+30h] [rbp-78h]
  hkResult v38; // [rsp+34h] [rbp-74h]
  hkResult v39; // [rsp+38h] [rbp-70h]
  hkResult v40; // [rsp+3Ch] [rbp-6Ch]
  hkResult v41; // [rsp+40h] [rbp-68h]
  __int64 v42; // [rsp+48h] [rbp-60h]
  __int64 v43; // [rsp+50h] [rbp-58h]
  UFG::RigHandle *result; // [rsp+B8h] [rbp+10h]
  hkResult v45; // [rsp+C0h] [rbp+18h]
  hkResult v46; // [rsp+C8h] [rbp+20h]

  v42 = -2i64;
  v2 = rig;
  v3 = this;
  v4 = &this->mRootTransformNode;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->mRootTransformNode.m_pPointer = 0i64;
  v5 = &this->mRigHandle;
  result = &this->mRigHandle;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mRigHandle.mPrev);
  v5->mLoadFunction = 0i64;
  v5->mUnloadFunction = 0i64;
  v5->mUserData = 0i64;
  v5->mUFGSkeleton = 0i64;
  v6 = 0i64;
  v3->mRootQsMatrix.m_translation = 0i64;
  v3->mRootQsMatrix.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  v3->mRootQsMatrix.m_scale = (hkVector4f)query.m_quad;
  v6.m128_f32[0] = (float)1;
  v3->mRootMatrix44.v0 = (UFG::qVector4)v6;
  v3->mRootMatrix44.v1 = (UFG::qVector4)_mm_shuffle_ps(v6, v6, 81);
  v3->mRootMatrix44.v2 = (UFG::qVector4)_mm_shuffle_ps(v6, v6, 69);
  v3->mRootMatrix44.v3 = (UFG::qVector4)_mm_shuffle_ps(v6, v6, 21);
  v3->mIsRootDirty = 0;
  v3->mCachedTransformChangeID = -1;
  v7 = v2->mNode.mUID;
  inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    inventory = UFG::qResourceWarehouse::GetInventory(v9, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = inventory;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v5->mPrev,
    0x39BC0A7Eu,
    v7,
    (UFG::qResourceData *)&v2->mNode,
    inventory);
  v3->mRigHandle.mUnloadFunction = SkeletalPose::RigUnloadedCallback;
  v3->mRigHandle.mLoadFunction = SkeletalPose::RigLoadedCallback;
  v3->mRigHandle.mUserData = v3;
  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v11 = ++*(_BYTE *)(v10 + 80);
  v12 = v11;
  *(_DWORD *)(v10 + 4 * v12) = 2;
  *(_QWORD *)(v10 + 8 * v12 + 16) = "hkaPose";
  *(_QWORD *)(v10 + 8 * v12 + 48) = 0i64;
  v13 = *(_BYTE *)(v10 + 81);
  if ( v11 > v13 )
    v13 = v11;
  *(_BYTE *)(v10 + 81) = v13;
  v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(v14[11], 80i64);
  v16 = (hkaPose *)v15;
  v43 = v15;
  if ( v15 )
  {
    *(_QWORD *)v15 = v2->mUFGSkeleton->mhkaSkeleton;
    *(_QWORD *)(v15 + 8) = 0i64;
    *(_DWORD *)(v15 + 16) = 0;
    *(_DWORD *)(v15 + 20) = 2147483648;
    *(_QWORD *)(v15 + 24) = 0i64;
    *(_DWORD *)(v15 + 32) = 0;
    *(_DWORD *)(v15 + 36) = 2147483648;
    *(_QWORD *)(v15 + 40) = 0i64;
    *(_DWORD *)(v15 + 48) = 0;
    *(_DWORD *)(v15 + 52) = 2147483648;
    *(_WORD *)(v15 + 56) = 0;
    *(_QWORD *)(v15 + 64) = 0i64;
    *(_DWORD *)(v15 + 72) = 0;
    *(_DWORD *)(v15 + 76) = 2147483648;
    v17 = *(_DWORD *)(*(_QWORD *)v15 + 48i64);
    v18 = (v17 + 3) & 0xFFFFFFFC;
    if ( (*(_DWORD *)(v15 + 36) & 0x3FFFFFFF) >= v18 )
      LODWORD(result) = 0;
    else
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (void *)(v15 + 24),
        v18,
        48);
    if ( (v16->m_localPose.m_capacityAndFlags & 0x3FFFFFFF) >= v18 )
      v45.m_enum = 0;
    else
      hkArrayUtil::_reserve(
        &v45,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v16->m_localPose,
        v18,
        48);
    if ( (v16->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) >= v18 )
      v46.m_enum = 0;
    else
      hkArrayUtil::_reserve(
        &v46,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v16->m_boneFlags,
        v18,
        4);
    v19 = v16->m_modelPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v19 >= v17 )
    {
      v37.m_enum = 0;
    }
    else
    {
      v20 = 2 * v19;
      v21 = v17;
      if ( v17 < v20 )
        v21 = v20;
      hkArrayUtil::_reserve(
        &v37,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v16->m_modelPose,
        v21,
        48);
    }
    v16->m_modelPose.m_size = v17;
    v22 = v16->m_localPose.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v22 >= v17 )
    {
      v38.m_enum = 0;
    }
    else
    {
      v23 = 2 * v22;
      v24 = v17;
      if ( v17 < v23 )
        v24 = v23;
      hkArrayUtil::_reserve(
        &v38,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v16->m_localPose,
        v24,
        48);
    }
    v16->m_localPose.m_size = v17;
    v25 = v16->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v25 >= v17 )
    {
      v39.m_enum = 0;
    }
    else
    {
      v26 = 2 * v25;
      v27 = v17;
      if ( v17 < v26 )
        v27 = v26;
      hkArrayUtil::_reserve(
        &v39,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v16->m_boneFlags,
        v27,
        4);
    }
    v16->m_boneFlags.m_size = v17;
    v28 = v16->m_skeleton->m_floatSlots.m_size;
    v29 = (v28 + 3) & 0xFFFFFFFC;
    if ( (v16->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) >= v29 )
      v40.m_enum = 0;
    else
      hkArrayUtil::_reserve(
        &v40,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v16->m_floatSlotValues,
        v29,
        4);
    v30 = v16->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v30 >= v28 )
    {
      v41.m_enum = 0;
    }
    else
    {
      v31 = 2 * v30;
      v32 = v28;
      if ( v28 < v31 )
        v32 = v31;
      hkArrayUtil::_reserve(
        &v41,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v16->m_floatSlotValues,
        v32,
        4);
    }
    v33 = v28 - v16->m_floatSlotValues.m_size;
    v34 = &v16->m_floatSlotValues.m_data[v16->m_floatSlotValues.m_size];
    v35 = v33;
    if ( v33 > 0 )
    {
      while ( v35 )
      {
        *v34 = 0.0;
        ++v34;
        --v35;
      }
    }
    v16->m_floatSlotValues.m_size = v28;
  }
  else
  {
    v16 = 0i64;
  }
  v3->mHavokPose = v16;
  v36 = *(_BYTE *)(v10 + 80);
  if ( v36 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v36 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  v3->mBoneUpdateCount = -1;
}

// File Line: 117
// RVA: 0x1BA190
void __fastcall SkeletalPose::~SkeletalPose(SkeletalPose *this)
{
  SkeletalPose *v1; // rbx
  hkaPose *v2; // rdi
  _QWORD **v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  v1 = this;
  this->mRigHandle.mLoadFunction = 0i64;
  this->mRigHandle.mUnloadFunction = 0i64;
  this->mRigHandle.mUserData = 0i64;
  v2 = this->mHavokPose;
  if ( v2 )
  {
    hkaPose::~hkaPose(this->mHavokPose);
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkaPose *, signed __int64))(*v3[11] + 16i64))(v3[11], v2, 80i64);
    v1->mHavokPose = 0i64;
  }
  v4 = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = v4;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mRigHandle.mPrev, v4);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mRigHandle.mPrev);
  v6 = &v1->mRootTransformNode;
  if ( v1->mRootTransformNode.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v1->mRootTransformNode.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v1->mRootTransformNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mRootTransformNode.mPrev;
  }
  v1->mRootTransformNode.m_pPointer = 0i64;
  v9 = v6->mPrev;
  v10 = v1->mRootTransformNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v1->mRootTransformNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mRootTransformNode.mPrev;
}

// File Line: 130
// RVA: 0x1BAB70
SkeletalPose *__fastcall SkeletalPose::Clone(SkeletalPose *this)
{
  SkeletalPose *v1; // rsi
  signed __int64 v2; // rbx
  char v3; // dl
  __int64 v4; // rax
  char v5; // cl
  UFG::allocator::free_link *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rdi
  char v9; // al
  UFG::qVector4 v10; // xmm3
  UFG::qVector4 v11; // xmm2
  UFG::qVector4 v12; // xmm1

  v1 = this;
  v2 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v3 = ++*(_BYTE *)(v2 + 80);
  v4 = v3;
  *(_DWORD *)(v2 + 4 * v4) = 2;
  *(_QWORD *)(v2 + 8 * v4 + 16) = "SkeletalPose";
  *(_QWORD *)(v2 + 8 * v4 + 48) = 0i64;
  v5 = *(_BYTE *)(v2 + 81);
  if ( v3 > v5 )
    v5 = v3;
  *(_BYTE *)(v2 + 81) = v5;
  v6 = UFG::qMalloc(0x100ui64, "SkeletalPose.Clone", 0i64);
  if ( v6 )
  {
    SkeletalPose::SkeletalPose((SkeletalPose *)v6, v1->mRigHandle.mNameUID);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  v9 = *(_BYTE *)(v2 + 80);
  if ( v9 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v9 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  SkeletalPose::syncTransformToRoot(v1);
  v10 = v1->mRootMatrix44.v1;
  v11 = v1->mRootMatrix44.v2;
  v12 = v1->mRootMatrix44.v3;
  *(UFG::qVector4 *)(v8 + 16) = v1->mRootMatrix44.v0;
  *(UFG::qVector4 *)(v8 + 32) = v10;
  *(UFG::qVector4 *)(v8 + 48) = v11;
  *(UFG::qVector4 *)(v8 + 64) = v12;
  *(hkVector4f *)(v8 + 80) = v1->mRootQsMatrix.m_translation;
  *(hkQuaternionf *)(v8 + 96) = v1->mRootQsMatrix.m_rotation;
  *(hkVector4f *)(v8 + 112) = v1->mRootQsMatrix.m_scale;
  *(_DWORD *)(v8 + 128) = v1->mIsRootDirty;
  *(_DWORD *)(v8 + 132) = v1->mCachedTransformChangeID;
  *(_DWORD *)v8 = v1->mBoneUpdateCount;
  return (SkeletalPose *)v8;
}

// File Line: 178
// RVA: 0x1BE3F0
void __fastcall SkeletalPose::SetToRestPose(SkeletalPose *this)
{
  SkeletalPose *v1; // rbx
  hkaPose *v2; // rcx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v3; // rax
  unsigned int v4; // ecx
  signed __int64 v5; // rdx
  __int64 v6; // r8
  hkQsTransformf *v7; // rcx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4

  v1 = this;
  hkaPose::setToReferencePose(this->mHavokPose);
  v2 = v1->mHavokPose;
  v1->mPoseAABBMin.x = 3.4028235e38;
  v1->mPoseAABBMin.y = 3.4028235e38;
  v1->mPoseAABBMin.z = 3.4028235e38;
  v1->mPoseAABBMax.x = -3.4028235e38;
  v1->mPoseAABBMax.y = -3.4028235e38;
  v1->mPoseAABBMax.z = -3.4028235e38;
  v3 = hkaPose::accessSyncedPoseModelSpace(v2);
  v4 = v3->m_size;
  if ( v4 > 1 )
  {
    v5 = 1i64;
    v6 = v4 - 1;
    do
    {
      v7 = v3->m_data;
      v8 = v1->mPoseAABBMin.x;
      if ( v8 >= v3->m_data[v5].m_translation.m_quad.m128_f32[0] )
        v8 = v3->m_data[v5].m_translation.m_quad.m128_f32[0];
      v1->mPoseAABBMin.x = v8;
      v9 = v1->mPoseAABBMin.y;
      if ( v9 >= v7[v5].m_translation.m_quad.m128_f32[1] )
        v9 = v7[v5].m_translation.m_quad.m128_f32[1];
      v1->mPoseAABBMin.y = v9;
      v10 = v1->mPoseAABBMin.z;
      if ( v10 >= v7[v5].m_translation.m_quad.m128_f32[2] )
        v10 = v7[v5].m_translation.m_quad.m128_f32[2];
      v1->mPoseAABBMin.z = v10;
      v11 = v1->mPoseAABBMax.x;
      if ( v11 <= v7[v5].m_translation.m_quad.m128_f32[0] )
        v11 = v7[v5].m_translation.m_quad.m128_f32[0];
      v1->mPoseAABBMax.x = v11;
      v12 = v1->mPoseAABBMax.y;
      if ( v12 <= v7[v5].m_translation.m_quad.m128_f32[1] )
        v12 = v7[v5].m_translation.m_quad.m128_f32[1];
      v1->mPoseAABBMax.y = v12;
      v13 = v1->mPoseAABBMax.z;
      if ( v13 <= v7[v5].m_translation.m_quad.m128_f32[2] )
        v13 = v7[v5].m_translation.m_quad.m128_f32[2];
      ++v5;
      v1->mPoseAABBMax.z = v13;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 213
// RVA: 0x1BBF50
void __fastcall SkeletalPose::Renormalize(SkeletalPose *this, bool syncedPose, bool skipScaleable)
{
  bool v3; // r15
  SkeletalPose *v4; // r12
  hkaPose *v5; // r9
  signed int v6; // edi
  hkaSkeleton *v7; // r13
  __int64 v8; // r14
  hkLifoAllocator *v9; // rax
  int v10; // edx
  float *v11; // rcx
  char *v12; // r8
  int v13; // er9
  float *v14; // rbx
  unsigned int v15; // esi
  hkQsTransformf *v16; // rax
  hkVector4f v17; // xmm5
  __m128 v18; // xmm4
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
  int v30; // er8
  float *array; // [rsp+38h] [rbp-28h]
  int v32; // [rsp+40h] [rbp-20h]
  int v33; // [rsp+44h] [rbp-1Ch]
  void *p; // [rsp+48h] [rbp-18h]
  int v35; // [rsp+50h] [rbp-10h]
  hkResult result; // [rsp+A0h] [rbp+40h]
  bool v37; // [rsp+A8h] [rbp+48h]

  v37 = syncedPose;
  v3 = skipScaleable;
  v4 = this;
  v5 = this->mHavokPose;
  v6 = v5->m_skeleton->m_bones.m_size;
  v7 = v5->m_skeleton;
  v8 = 0i64;
  array = 0i64;
  v32 = 0;
  v33 = 2147483648;
  v35 = v6;
  if ( v6 )
  {
    v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (((4 * v6 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v11 = (float *)v9->m_cur;
    v12 = (char *)v11 + v10;
    if ( v10 > v9->m_slabSize || v12 > v9->m_end )
      v11 = (float *)hkLifoAllocator::allocateFromNewSlab(v9, v10);
    else
      v9->m_cur = v12;
  }
  else
  {
    v11 = 0i64;
  }
  array = v11;
  v33 = v6 | 0x80000000;
  p = v11;
  if ( (signed int)((v6 | 0x80000000) & 0x3FFFFFFF) < v6 )
  {
    v13 = v6;
    if ( v6 < (signed int)(2 * ((v6 | 0x80000000) & 0x3FFFFFFF)) )
      v13 = 2 * ((v6 | 0x80000000) & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v13, 4);
  }
  v32 = v6;
  v14 = array;
  *(_QWORD *)&result.m_enum = array;
  v15 = 0;
  if ( v6 )
  {
    do
    {
      if ( !v3 || *(&v7->m_bones.m_data->m_lockTranslation.m_bool + v8) )
      {
        *v14 = 1.0;
      }
      else
      {
        *v14 = 0.0;
        v16 = hkaPose::accessBoneLocalSpace(v4->mHavokPose, v15);
        v17.m_quad = (__m128)v16->m_scale;
        v18 = v16->m_rotation.m_vec.m_quad;
        v19 = _mm_mul_ps(v18, v18);
        v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 78), v19);
        v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20);
        v22 = _mm_rsqrt_ps(v21);
        v16->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                         _mm_mul_ps(
                                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                                           _mm_mul_ps(*(__m128 *)_xmm, v22)),
                                         v18);
        v16->m_scale = (hkVector4f)v17.m_quad;
      }
      ++v15;
      v8 += 16i64;
      ++v14;
    }
    while ( v15 < v6 );
    v14 = *(float **)&result.m_enum;
    LODWORD(v8) = 0;
  }
  v23 = v4->mHavokPose;
  if ( v37 )
    v24 = hkaPose::accessSyncedPoseLocalSpace(v23);
  else
    v24 = hkaPose::accessUnsyncedPoseLocalSpace(v23);
  hkQsTransformf::fastRenormalizeBatch(v24->m_data, v14, v6);
  v25 = (char *)p;
  v26 = v32;
  if ( p == array )
    v26 = v8;
  v32 = v26;
  v27 = v35;
  v28 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v29 = (4 * v27 + 127) & 0xFFFFFF80;
  v30 = (v29 + 15) & 0xFFFFFFF0;
  if ( v29 > v28->m_slabSize || &v25[v30] != v28->m_cur || v28->m_firstNonLifoEnd == v25 )
    hkLifoAllocator::slowBlockFree(v28, v25, v30);
  else
    v28->m_cur = v25;
  v32 = v8;
  if ( v33 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v33);
}

// File Line: 293
// RVA: 0x1BE540
void __fastcall UFG::EncounterUnitComponent::SetGroupVehicle(SkeletalPose *this, UFG::TransformNodeComponent *transformNodeRoot)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mRootTransformNode.mPrev;
  if ( this->mRootTransformNode.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
  }
  v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)transformNodeRoot;
  if ( transformNodeRoot )
  {
    v5 = transformNodeRoot->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    v2->mNext = &transformNodeRoot->m_SafePointerList.mNode;
    transformNodeRoot->m_SafePointerList.mNode.mPrev = v2;
  }
}

// File Line: 304
// RVA: 0x1BE8F0
void __fastcall SkeletalPose::syncTransformToRoot(SkeletalPose *this)
{
  UFG::SimComponent *v1; // rdi
  SkeletalPose *v2; // rbx
  unsigned int v3; // esi
  UFG::qVector4 v4; // xmm3
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm1

  v1 = this->mRootTransformNode.m_pPointer;
  v2 = this;
  if ( v1 )
  {
    v3 = *(_DWORD *)&v1[1].m_Flags;
    if ( !sCheckCachedChangeID || this->mCachedTransformChangeID != v3 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1);
      v4 = *(UFG::qVector4 *)&v1[2].m_SafePointerList.mNode.mNext;
      v5 = *(UFG::qVector4 *)&v1[2].m_Flags;
      v6 = (UFG::qVector4)v1[2].m_BoundComponentHandles;
      v2->mRootMatrix44.v0 = *(UFG::qVector4 *)&v1[2].vfptr;
      v2->mRootMatrix44.v1 = v4;
      v2->mRootMatrix44.v2 = v5;
      v2->mRootMatrix44.v3 = v6;
      v2->mIsRootDirty = 1;
      v2->mCachedTransformChangeID = v3;
    }
  }
}

// File Line: 320
// RVA: 0x1BBED0
bool __fastcall SkeletalPose::HasPoseChanged(SkeletalPose *this)
{
  UFG::SimComponent *v1; // rdx
  bool result; // al

  v1 = this->mRootTransformNode.m_pPointer;
  if ( v1 )
    result = *(_DWORD *)&v1[1].m_Flags != this->mCachedTransformChangeID;
  else
    result = 0;
  return result;
}

// File Line: 342
// RVA: 0x1BE2F0
void __fastcall SkeletalPose::SetRoot(SkeletalPose *this, UFG::qMatrix44 *newRoot, bool forceTeleportEvent)
{
  UFG::qVector4 v3; // xmm3
  UFG::qVector4 v4; // xmm2
  SkeletalPose *v5; // rbx
  bool v6; // di
  UFG::qVector4 v7; // xmm1
  UFG::TransformNodeComponent *v8; // rcx

  v3 = newRoot->v1;
  v4 = newRoot->v2;
  v5 = this;
  v6 = forceTeleportEvent;
  v7 = newRoot->v3;
  this->mRootMatrix44.v0 = newRoot->v0;
  this->mRootMatrix44.v1 = v3;
  this->mRootMatrix44.v2 = v4;
  this->mRootMatrix44.v3 = v7;
  this->mIsRootDirty = 1;
  v8 = (UFG::TransformNodeComponent *)this->mRootTransformNode.m_pPointer;
  if ( v8 )
    UFG::TransformNodeComponent::SetWorldTransform(v8, newRoot);
  if ( v6 )
    SkeletalPose::forceTeleport(v5);
}

// File Line: 356
// RVA: 0x1BE270
void __fastcall SkeletalPose::SetRoot(SkeletalPose *this, hkQsTransformf *newRoot, bool forceTeleportEvent)
{
  SkeletalPose *v3; // rbx
  bool v4; // si
  UFG::TransformNodeComponent *v5; // rcx

  v3 = this;
  this->mRootQsMatrix.m_translation = newRoot->m_translation;
  v4 = forceTeleportEvent;
  this->mRootQsMatrix.m_rotation = newRoot->m_rotation;
  this->mRootQsMatrix.m_scale = newRoot->m_scale;
  hkQsTransformf::get4x4ColumnMajor(newRoot, &this->mRootMatrix44.v0.x);
  v5 = (UFG::TransformNodeComponent *)v3->mRootTransformNode.m_pPointer;
  v3->mIsRootDirty = 0;
  if ( v5 )
    UFG::TransformNodeComponent::SetWorldTransform(v5, &v3->mRootMatrix44);
  if ( v4 )
    SkeletalPose::forceTeleport(v3);
}

// File Line: 366
// RVA: 0x1BE360
void __fastcall SkeletalPose::SetRootTranslation(SkeletalPose *this, UFG::qVector3 *trans, bool forceTeleportEvent)
{
  float v3; // eax
  float v4; // xmm1_4
  float v5; // xmm0_4
  bool v6; // di
  SkeletalPose *v7; // rbx
  UFG::TransformNodeComponent *v8; // rcx

  v3 = trans->x;
  v4 = trans->y;
  v5 = trans->z;
  this->mRootMatrix44.v3.w = 1.0;
  this->mRootMatrix44.v3.x = v3;
  v6 = forceTeleportEvent;
  this->mRootMatrix44.v3.y = v4;
  this->mRootMatrix44.v3.z = v5;
  v7 = this;
  if ( !this->mIsRootDirty )
    this->mRootQsMatrix.m_translation.m_quad = _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps((__m128)LODWORD(trans->x), (__m128)LODWORD(trans->z)),
                                                 _mm_unpacklo_ps(
                                                   (__m128)LODWORD(trans->y),
                                                   (__m128)(unsigned int)FLOAT_1_0));
  v8 = (UFG::TransformNodeComponent *)this->mRootTransformNode.m_pPointer;
  if ( v8 )
    UFG::TransformNodeComponent::SetWorldTransform(v8, &v7->mRootMatrix44);
  if ( v6 )
    SkeletalPose::forceTeleport(v7);
}

// File Line: 376
// RVA: 0x1BE810
void __fastcall SkeletalPose::forceTeleport(SkeletalPose *this)
{
  SkeletalPose *v1; // rbx
  UFG::SimComponent *v2; // rax
  UFG::SimObject *v3; // rdi
  UFG::allocator::free_link *v4; // rax
  UFG::TeleportEvent *v5; // rbp
  unsigned int v6; // esi
  UFG::SimComponent *v7; // rdi
  UFG::SimComponent *v8; // rbx

  v1 = this;
  v2 = this->mRootTransformNode.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_pSimObject;
    v4 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
    v5 = (UFG::TeleportEvent *)v4;
    if ( v4 )
    {
      v6 = v3->mNode.mUID;
      v7 = v1->mRootTransformNode.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->mRootTransformNode.m_pPointer);
      v8 = v1->mRootTransformNode.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v8);
      UFG::TeleportEvent::TeleportEvent(
        v5,
        (UFG::qVector3 *)&v8[2].m_BoundComponentHandles,
        (UFG::qVector3 *)&v7[2],
        v6,
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
  SkeletalPose *v1; // rbx
  hkTransformf transform; // [rsp+20h] [rbp-48h]

  v1 = this;
  SkeletalPose::syncTransformToRoot(this);
  if ( v1->mIsRootDirty )
  {
    hkTransformf::set4x4ColumnMajor(&transform, &v1->mRootMatrix44.v0.x);
    hkQsTransformf::setFromTransformNoScale(&v1->mRootQsMatrix, &transform);
    v1->mIsRootDirty = 0;
  }
  return &v1->mRootQsMatrix;
}

// File Line: 393
// RVA: 0x1BBDD0
void __fastcall SkeletalPose::GetRootMatrix(SkeletalPose *this, UFG::qMatrix44 *matrixRoot)
{
  UFG::qMatrix44 *v2; // rdi
  SkeletalPose *v3; // rbx
  UFG::qVector4 v4; // xmm3
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm1

  v2 = matrixRoot;
  v3 = this;
  SkeletalPose::syncTransformToRoot(this);
  v4 = v3->mRootMatrix44.v1;
  v5 = v3->mRootMatrix44.v2;
  v6 = v3->mRootMatrix44.v3;
  v2->v0 = v3->mRootMatrix44.v0;
  v2->v1 = v4;
  v2->v2 = v5;
  v2->v3 = v6;
}

// File Line: 399
// RVA: 0x1BBB90
void __fastcall SkeletalPose::GetPositionWS(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixWS)
{
  UFG::qMatrix44 *v3; // rsi
  __int64 v4; // rbx
  SkeletalPose *v5; // rdi
  hkQsTransformf *v6; // r9
  __m128 v7; // xmm7
  __m128 v8; // xmm6
  __m128 v9; // xmm8
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm5
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm0
  __m128 v19; // xmm6
  __m128 v20; // xmm2
  hkVector4f v21; // xmm0
  hkQsTransformf v22; // [rsp+20h] [rbp-A8h]
  hkTransformf transform; // [rsp+50h] [rbp-78h]

  v3 = matrixWS;
  v4 = boneID;
  v5 = this;
  SkeletalPose::syncTransformToRoot(this);
  v6 = &hkaPose::getSyncedPoseModelSpace(v5->mHavokPose)->m_data[v4];
  v7 = v6->m_translation.m_quad;
  v8 = v6->m_rotation.m_vec.m_quad;
  v9 = v6->m_scale.m_quad;
  if ( v5->mIsRootDirty )
  {
    hkTransformf::set4x4ColumnMajor(&transform, &v5->mRootMatrix44.v0.x);
    hkQsTransformf::setFromTransformNoScale(&v5->mRootQsMatrix, &transform);
    v5->mIsRootDirty = 0;
  }
  v10 = v5->mRootQsMatrix.m_rotation.m_vec.m_quad;
  v11 = _mm_mul_ps(v5->mRootQsMatrix.m_rotation.m_vec.m_quad, v7);
  v12 = _mm_shuffle_ps(v5->mRootQsMatrix.m_rotation.m_vec.m_quad, v10, 255);
  v13 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v10),
          _mm_mul_ps(_mm_shuffle_ps(v5->mRootQsMatrix.m_rotation.m_vec.m_quad, v10, 201), v7));
  v14 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                _mm_shuffle_ps(v11, v11, 170)),
              v10),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), v7)),
          _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v12));
  v15 = _mm_mul_ps(_mm_shuffle_ps(v5->mRootQsMatrix.m_rotation.m_vec.m_quad, v10, 201), v8);
  v16 = _mm_shuffle_ps(v8, v8, 255);
  v22.m_translation.m_quad = _mm_add_ps(_mm_add_ps(v14, v14), v5->mRootQsMatrix.m_translation.m_quad);
  v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v10), v15);
  v18 = v8;
  v19 = _mm_mul_ps(v8, v10);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 201), _mm_mul_ps(v18, v12)), _mm_mul_ps(v16, v10));
  v21.m_quad = _mm_mul_ps(v5->mRootQsMatrix.m_scale.m_quad, v9);
  v22.m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                  v20,
                                  _mm_unpackhi_ps(
                                    v20,
                                    _mm_sub_ps(
                                      _mm_mul_ps(v16, v12),
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                                        _mm_shuffle_ps(v19, v19, 170)))),
                                  196);
  v22.m_scale = (hkVector4f)v21.m_quad;
  hkQsTransformf::get4x4ColumnMajor(&v22, &v3->v0.x);
}

// File Line: 415
// RVA: 0x1BBE10
void __fastcall SkeletalPose::GetTranslationWS(SkeletalPose *this, int boneID, UFG::qVector3 *translationWS)
{
  UFG::qVector3 *v3; // rsi
  __int64 v4; // rbx
  SkeletalPose *v5; // rdi
  hkaPose *v6; // r9
  hkQsTransformf *v7; // rbx
  float v8; // xmm1_4
  float v9; // xmm0_4
  hkVector4f v10; // [rsp+20h] [rbp-58h]
  hkTransformf transform; // [rsp+30h] [rbp-48h]

  v3 = translationWS;
  v4 = boneID;
  v5 = this;
  SkeletalPose::syncTransformToRoot(this);
  v6 = v5->mHavokPose;
  if ( v6->m_boneFlags.m_data[v4] & 2 )
    v7 = hkaPose::calculateBoneModelSpace(v5->mHavokPose, v4);
  else
    v7 = &v6->m_modelPose.m_data[v4];
  if ( v5->mIsRootDirty )
  {
    hkTransformf::set4x4ColumnMajor(&transform, &v5->mRootMatrix44.v0.x);
    hkQsTransformf::setFromTransformNoScale(&v5->mRootQsMatrix, &transform);
    v5->mIsRootDirty = 0;
  }
  hkVector4f::setTransformedPos(&v10, &v5->mRootQsMatrix, &v7->m_translation);
  v8 = v10.m_quad.m128_f32[1];
  LODWORD(v3->x) = v10.m_quad.m128_i32[0];
  v9 = v10.m_quad.m128_f32[2];
  v3->y = v8;
  v3->z = v9;
}

// File Line: 448
// RVA: 0x1BD0C0
void __fastcall SkeletalPose::SetPositionWS(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixWS)
{
  UFG::qMatrix44 *v3; // rbx
  __int64 v4; // rbp
  SkeletalPose *v5; // rsi
  __m128i v6; // xmm0
  __m128 v7; // xmm13
  __m128 v8; // xmm14
  __m128 v9; // xmm7
  __m128 v10; // xmm0
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
  hkaPose *v23; // rsi
  __int64 v24; // r8
  __m128 v25; // xmm11
  __m128 v26; // xmm12
  __int64 v27; // rcx
  int v28; // eax
  __int64 v29; // r13
  __int64 v30; // r14
  signed __int64 v31; // rbp
  __int64 v32; // rdx
  unsigned int *v33; // rcx
  hkQsTransformf *v34; // r12
  hkQsTransformf *v35; // r15
  hkQsTransformf *v36; // rdi
  __m128 v37; // xmm3
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
  hkQsTransformf *v54; // rax
  __int64 i; // rcx
  unsigned int *v56; // rdx
  unsigned int v57; // eax
  __m128 *v58; // rax
  hkVector4f v59; // [rsp+20h] [rbp-178h]
  __m128 v60; // [rsp+30h] [rbp-168h]
  __m128 v61; // [rsp+40h] [rbp-158h]
  hkTransformf transform; // [rsp+50h] [rbp-148h]
  hkQsTransformf v63; // [rsp+90h] [rbp-108h]
  int v64; // [rsp+1A8h] [rbp+10h]
  __int64 v65; // [rsp+1B8h] [rbp+20h]

  if ( boneID >= 0 )
  {
    v3 = matrixWS;
    v4 = boneID;
    v5 = this;
    SkeletalPose::syncTransformToRoot(this);
    hkTransformf::set4x4ColumnMajor(&transform, &v3->v0.x);
    hkQsTransformf::setFromTransformNoScale(&v63, &transform);
    if ( v5->mIsRootDirty )
    {
      hkTransformf::set4x4ColumnMajor(&transform, &v5->mRootMatrix44.v0.x);
      hkQsTransformf::setFromTransformNoScale(&v5->mRootQsMatrix, &transform);
      v5->mIsRootDirty = 0;
    }
    hkVector4f::setRotatedInverseDir(&v59, &v5->mRootQsMatrix.m_rotation, &v5->mRootQsMatrix.m_translation);
    v6 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    v7 = (__m128)_mm_shuffle_epi32(v6, 0);
    v8 = (__m128)_mm_shuffle_epi32(v6, 64);
    v9 = _mm_xor_ps(v5->mRootQsMatrix.m_rotation.m_vec.m_quad, v8);
    v10 = v5->mRootQsMatrix.m_scale.m_quad;
    v11 = _mm_rcp_ps(v10);
    v59.m_quad = _mm_xor_ps(v59.m_quad, v7);
    v60 = v9;
    v12 = _mm_shuffle_ps(v9, v9, 255);
    v13 = _mm_shuffle_ps(v9, v9, 201);
    v14 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v63.m_translation.m_quad, v63.m_translation.m_quad, 201), v9),
            _mm_mul_ps(v13, v63.m_translation.m_quad));
    v15 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10, v11)), v11), 4);
    v16 = _mm_mul_ps(v63.m_translation.m_quad, v9);
    v61 = (__m128)_mm_srli_si128(v15, 4);
    v17 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                  _mm_shuffle_ps(v16, v16, 170)),
                v9),
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), v63.m_translation.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v12));
    v18 = _mm_shuffle_ps(v63.m_rotation.m_vec.m_quad, v63.m_rotation.m_vec.m_quad, 255);
    v19 = _mm_mul_ps(v63.m_rotation.m_vec.m_quad, v9);
    v20 = _mm_add_ps(_mm_add_ps(v17, v17), v59.m_quad);
    v21 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v63.m_rotation.m_vec.m_quad, v63.m_rotation.m_vec.m_quad, 201), v9),
            _mm_mul_ps(v13, v63.m_rotation.m_vec.m_quad));
    v22 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v21, v21, 201), _mm_mul_ps(v63.m_rotation.m_vec.m_quad, v12)),
            _mm_mul_ps(v9, v18));
    v23 = v5->mHavokPose;
    v24 = v4;
    v65 = v4;
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
    v26 = _mm_mul_ps(v63.m_scale.m_quad, v61);
    v27 = v23->m_skeleton->m_bones.m_size;
    v23->m_boneFlags.m_data[v4] |= 4u;
    v28 = v4 + 1;
    v29 = v27;
    v30 = (signed int)v4 + 1;
    v64 = v4 + 1;
    if ( v30 < v27 )
    {
      v31 = v28;
      do
      {
        LOWORD(v32) = v23->m_skeleton->m_parentIndices.m_data[v30];
        if ( (_WORD)v32 != -1 )
        {
          v33 = v23->m_boneFlags.m_data;
          if ( v33[(signed __int16)v32] & 4 )
          {
            if ( v33[v30] & 1 )
            {
              v34 = v23->m_modelPose.m_data;
              if ( (_WORD)v32 == -1 )
              {
                v54 = v23->m_localPose.m_data;
                v54[v31].m_translation = v34[v31].m_translation;
                v54[v31].m_rotation = v34[v31].m_rotation;
                v54[v31].m_scale = v34[v31].m_scale;
              }
              else
              {
                v32 = (signed __int16)v32;
                if ( v33[(signed __int16)v32] & 2 )
                  v35 = hkaPose::calculateBoneModelSpace(v23, v32);
                else
                  v35 = &v34[v32];
                v36 = v23->m_localPose.m_data;
                hkVector4f::setRotatedInverseDir(&transform.m_rotation.m_col0, &v35->m_rotation, &v35->m_translation);
                v37 = v34[v31].m_translation.m_quad;
                v38 = v35->m_scale.m_quad;
                v39 = _mm_rcp_ps(v38);
                v40 = _mm_xor_ps(v8, v35->m_rotation.m_vec.m_quad);
                v41 = _mm_shuffle_ps(v40, v40, 255);
                v42 = (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v38, v39)), v39),
                                  4),
                                4);
                v43 = _mm_mul_ps(v40, v37);
                v44 = _mm_shuffle_ps(v40, v40, 201);
                v45 = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), v40),
                        _mm_mul_ps(v34[v31].m_translation.m_quad, v44));
                v46 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                              _mm_shuffle_ps(v43, v43, 170)),
                            v40),
                          _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v41, v41), (__m128)xmmword_141A711B0), v37)),
                        _mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), v41));
                v36[v31].m_translation.m_quad = _mm_add_ps(
                                                  _mm_add_ps(v46, v46),
                                                  _mm_xor_ps(transform.m_rotation.m_col0.m_quad, v7));
                v47 = v34[v31].m_rotation.m_vec.m_quad;
                v48 = _mm_shuffle_ps(v34[v31].m_rotation.m_vec.m_quad, v47, 255);
                v49 = _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v40);
                v50 = _mm_mul_ps(v40, v48);
                v51 = _mm_mul_ps(v40, v47);
                v52 = _mm_sub_ps(v49, _mm_mul_ps(v34[v31].m_rotation.m_vec.m_quad, v44));
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
              }
              v23->m_boneFlags.m_data[v30] &= 0xFFFFFFFE;
            }
            v23->m_boneFlags.m_data[v30] |= 4u;
            v23->m_modelInSync.m_bool = 0;
          }
        }
        ++v30;
        ++v31;
      }
      while ( v30 < v29 );
      v24 = v65;
      v28 = v64;
    }
    for ( i = v28; i < v29; ++i )
    {
      v56 = v23->m_boneFlags.m_data;
      v57 = v56[i];
      if ( v57 & 4 )
        v56[i] = v57 & 0xFFFFFFFB | 2;
    }
    v58 = &v23->m_modelPose.m_data[v24].m_translation.m_quad;
    *v58 = v20;
    v58[1] = v25;
    v58[2] = v26;
    v23->m_boneFlags.m_data[v24] = 1;
    v23->m_localInSync.m_bool = 0;
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
  __m128i v10; // xmm0
  __m128 v11; // xmm13
  __m128 v12; // xmm14
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm8
  __m128 v16; // xmm6
  __m128 v17; // xmm7
  hkaPose *v18; // rsi
  __int64 v19; // r8
  __m128 v20; // xmm4
  __m128 v21; // xmm12
  __m128 v22; // xmm1
  __m128 v23; // xmm5
  __int64 v24; // r13
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
  signed __int64 v40; // rbp
  __int64 v41; // rdx
  unsigned int *v42; // rcx
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
  hkQsTransformf *v62; // rax
  __int64 i; // rcx
  unsigned int *v64; // rdx
  unsigned int v65; // eax
  __m128 *v66; // rax
  __int64 v67; // [rsp+20h] [rbp-178h]
  __int64 v68; // [rsp+28h] [rbp-170h]
  __int64 v69; // [rsp+30h] [rbp-168h]
  hkVector4f v70; // [rsp+40h] [rbp-158h]
  __m128 v71; // [rsp+50h] [rbp-148h]
  __m128 v72; // [rsp+60h] [rbp-138h]
  hkTransformf transform; // [rsp+70h] [rbp-128h]
  SkeletalPose *v74; // [rsp+1A0h] [rbp+8h]
  int *v75; // [rsp+1A8h] [rbp+10h]
  hkQsTransformf *v76; // [rsp+1B0h] [rbp+18h]
  int v77; // [rsp+1B8h] [rbp+20h]

  v76 = xformWS;
  v75 = boneID;
  v74 = this;
  v4 = count;
  v5 = xformWS;
  v6 = boneID;
  v7 = this;
  SkeletalPose::syncTransformToRoot(this);
  v8 = 0i64;
  v67 = 0i64;
  if ( v7->mIsRootDirty )
  {
    hkTransformf::set4x4ColumnMajor(&transform, &v7->mRootMatrix44.v0.x);
    hkQsTransformf::setFromTransformNoScale(&v7->mRootQsMatrix, &transform);
    v7->mIsRootDirty = 0;
  }
  hkVector4f::setRotatedInverseDir(&v70, &v7->mRootQsMatrix.m_rotation, &v7->mRootQsMatrix.m_translation);
  v9 = v4;
  v10 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v68 = v4;
  v11 = (__m128)_mm_shuffle_epi32(v10, 0);
  v12 = (__m128)_mm_shuffle_epi32(v10, 64);
  v13 = v7->mRootQsMatrix.m_scale.m_quad;
  v14 = _mm_rcp_ps(v13);
  v15 = _mm_xor_ps(v70.m_quad, v11);
  v70.m_quad = v15;
  v16 = _mm_xor_ps(v12, v7->mRootQsMatrix.m_rotation.m_vec.m_quad);
  v71 = v16;
  v17 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v13, v14)), v14), 4),
                  4);
  v72 = v17;
  if ( (signed int)v4 > 0 )
  {
    while ( 1 )
    {
      v18 = v7->mHavokPose;
      v19 = v6[v8];
      v69 = v6[v8];
      v20 = _mm_shuffle_ps(v16, v16, 201);
      v21 = _mm_mul_ps(v5->m_scale.m_quad, v17);
      v22 = _mm_mul_ps(v16, v5->m_translation.m_quad);
      v23 = _mm_shuffle_ps(v16, v16, 255);
      v24 = v18->m_skeleton->m_bones.m_size;
      v25 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v5->m_translation.m_quad, v5->m_translation.m_quad, 201), v16),
              _mm_mul_ps(v20, v5->m_translation.m_quad));
      v26 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170));
      v27 = v16;
      v28 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v23, v23), (__m128)xmmword_141A711B0), v5->m_translation.m_quad);
      v29 = v5->m_rotation.m_vec.m_quad;
      v18->m_boneFlags.m_data[v19] |= 4u;
      v30 = v19 + 1;
      v31 = (signed int)v19 + 1;
      v77 = v19 + 1;
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
      if ( v31 < v24 )
      {
        v40 = v30;
        do
        {
          LOWORD(v41) = v18->m_skeleton->m_parentIndices.m_data[v31];
          if ( (_WORD)v41 != -1 )
          {
            v42 = v18->m_boneFlags.m_data;
            if ( v42[(signed __int16)v41] & 4 )
            {
              if ( v42[v31] & 1 )
              {
                v43 = v18->m_modelPose.m_data;
                if ( (_WORD)v41 == -1 )
                {
                  v62 = v18->m_localPose.m_data;
                  v62[v40].m_translation = v43[v40].m_translation;
                  v62[v40].m_rotation = v43[v40].m_rotation;
                  v62[v40].m_scale = v43[v40].m_scale;
                }
                else
                {
                  v41 = (signed __int16)v41;
                  if ( v42[(signed __int16)v41] & 2 )
                    v44 = hkaPose::calculateBoneModelSpace(v18, v41);
                  else
                    v44 = &v43[v41];
                  v45 = v18->m_localPose.m_data;
                  hkVector4f::setRotatedInverseDir(&transform.m_rotation.m_col0, &v44->m_rotation, &v44->m_translation);
                  v46 = v43[v40].m_translation.m_quad;
                  v47 = _mm_rcp_ps(v44->m_scale.m_quad);
                  v48 = _mm_xor_ps(v44->m_rotation.m_vec.m_quad, v12);
                  v49 = _mm_shuffle_ps(v48, v48, 255);
                  v50 = _mm_shuffle_ps(v48, v48, 201);
                  v51 = _mm_mul_ps(v48, v46);
                  v52 = _mm_sub_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v48),
                          _mm_mul_ps(v43[v40].m_translation.m_quad, v50));
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
                  v56 = _mm_shuffle_ps(v43[v40].m_rotation.m_vec.m_quad, v55, 255);
                  v57 = _mm_mul_ps(_mm_shuffle_ps(v55, v55, 201), v48);
                  v58 = _mm_mul_ps(v48, v56);
                  v59 = _mm_mul_ps(v48, v55);
                  v60 = _mm_sub_ps(v57, _mm_mul_ps(v43[v40].m_rotation.m_vec.m_quad, v50));
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
                }
                v18->m_boneFlags.m_data[v31] &= 0xFFFFFFFE;
              }
              v18->m_boneFlags.m_data[v31] |= 4u;
              v18->m_modelInSync.m_bool = 0;
            }
          }
          ++v31;
          ++v40;
        }
        while ( v31 < v24 );
        v8 = v67;
        v19 = v69;
        v5 = v76;
        v30 = v77;
        v9 = v68;
        v6 = v75;
      }
      for ( i = v30; i < v24; ++i )
      {
        v64 = v18->m_boneFlags.m_data;
        v65 = v64[i];
        if ( v65 & 4 )
          v64[i] = v65 & 0xFFFFFFFB | 2;
      }
      ++v8;
      ++v5;
      v67 = v8;
      v76 = v5;
      v66 = &v18->m_modelPose.m_data[v19].m_translation.m_quad;
      *v66 = v36;
      v66[1] = v39;
      v66[2] = v21;
      v18->m_boneFlags.m_data[v19] = 1;
      v18->m_localInSync.m_bool = 0;
      if ( v8 >= v9 )
        break;
      v17 = v72;
      v16 = v71;
      v15 = v70.m_quad;
      v7 = v74;
    }
  }
}

// File Line: 517
// RVA: 0x1BBD50
hkQsTransformf *__fastcall SkeletalPose::GetTranslationMS(SkeletalPose *this, int boneID)
{
  hkaPose *v2; // r8
  hkQsTransformf *result; // rax

  v2 = this->mHavokPose;
  if ( v2->m_boneFlags.m_data[boneID] & 2 )
    result = hkaPose::calculateBoneModelSpace(v2, boneID);
  else
    result = &v2->m_modelPose.m_data[boneID];
  return result;
}

// File Line: 526
// RVA: 0x1BBA30
void __fastcall SkeletalPose::GetPositionMS(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixMS)
{
  hkaPose *v3; // r9
  UFG::qMatrix44 *v4; // rbx
  hkQsTransformf *v5; // rax

  v3 = this->mHavokPose;
  v4 = matrixMS;
  if ( v3->m_boneFlags.m_data[boneID] & 2 )
  {
    v5 = hkaPose::calculateBoneModelSpace(v3, boneID);
    hkQsTransformf::get4x4ColumnMajor(v5, &v4->v0.x);
  }
  else
  {
    hkQsTransformf::get4x4ColumnMajor(&v3->m_modelPose.m_data[boneID], &matrixMS->v0.x);
  }
}

// File Line: 536
// RVA: 0x1BBA90
void __fastcall SkeletalPose::GetPositionMS_ReNormalize(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixMS)
{
  hkaPose *v3; // r9
  UFG::qMatrix44 *v4; // rbx
  hkQsTransformf *v5; // rax
  __m128 v6; // xmm3
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  hkQsTransformf v11; // [rsp+20h] [rbp-38h]

  v3 = this->mHavokPose;
  v4 = matrixMS;
  if ( v3->m_boneFlags.m_data[boneID] & 2 )
    v5 = hkaPose::calculateBoneModelSpace(v3, boneID);
  else
    v5 = &v3->m_modelPose.m_data[boneID];
  v11.m_translation = v5->m_translation;
  v6 = v5->m_rotation.m_vec.m_quad;
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_shuffle_ps(v7, v7, 78), v7);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 177), v8);
  v10 = _mm_rsqrt_ps(v9);
  v11.m_scale = (hkVector4f)_xmm;
  v11.m_rotation.m_vec.m_quad = _mm_mul_ps(
                                  v6,
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                                    _mm_mul_ps(*(__m128 *)_xmm, v10)));
  hkQsTransformf::get4x4ColumnMajor(&v11, &v4->v0.x);
}

// File Line: 569
// RVA: 0x1BDF10
void __fastcall SkeletalPose::SetQsTransformMS(SkeletalPose *this, int boneID, hkQsTransformf *transformMS)
{
  hkaPose *v3; // rsi
  hkQsTransformf *v4; // r9
  __int64 v5; // r8
  __int64 v6; // rcx
  int v7; // eax
  __int64 v8; // r14
  __int64 v9; // r13
  signed __int64 v10; // rbp
  __int64 v11; // rdx
  unsigned int *v12; // rcx
  hkQsTransformf *v13; // r12
  hkQsTransformf *v14; // r15
  hkQsTransformf *v15; // rdi
  __m128 v16; // xmm3
  __m128i v17; // xmm0
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
  hkQsTransformf *v36; // rax
  __int64 i; // rcx
  unsigned int *v38; // rdx
  unsigned int v39; // eax
  hkVector4f *v40; // rax
  hkVector4f v41; // [rsp+20h] [rbp-A8h]
  int v42; // [rsp+D8h] [rbp+10h]
  hkQsTransformf *v43; // [rsp+E0h] [rbp+18h]
  __int64 v44; // [rsp+E8h] [rbp+20h]

  if ( boneID >= 0 )
  {
    v43 = transformMS;
    v3 = this->mHavokPose;
    v4 = transformMS;
    v5 = boneID;
    v6 = v3->m_skeleton->m_bones.m_size;
    v3->m_boneFlags.m_data[boneID] |= 4u;
    v7 = boneID + 1;
    v44 = boneID;
    v8 = boneID + 1;
    v42 = boneID + 1;
    v9 = v6;
    if ( v8 < v6 )
    {
      v10 = v7;
      do
      {
        LOWORD(v11) = v3->m_skeleton->m_parentIndices.m_data[v8];
        if ( (_WORD)v11 != -1 )
        {
          v12 = v3->m_boneFlags.m_data;
          if ( v12[(signed __int16)v11] & 4 )
          {
            if ( v12[v8] & 1 )
            {
              v13 = v3->m_modelPose.m_data;
              if ( (_WORD)v11 == -1 )
              {
                v36 = v3->m_localPose.m_data;
                v36[v10].m_translation = v13[v10].m_translation;
                v36[v10].m_rotation = v13[v10].m_rotation;
                v36[v10].m_scale = v13[v10].m_scale;
              }
              else
              {
                v11 = (signed __int16)v11;
                if ( v12[(signed __int16)v11] & 2 )
                  v14 = hkaPose::calculateBoneModelSpace(v3, v11);
                else
                  v14 = &v13[v11];
                v15 = v3->m_localPose.m_data;
                hkVector4f::setRotatedInverseDir(&v41, &v14->m_rotation, &v14->m_translation);
                v16 = v13[v10].m_translation.m_quad;
                v17 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
                v18 = (__m128)_mm_shuffle_epi32(v17, 0);
                v19 = (__m128)_mm_shuffle_epi32(v17, 64);
                v20 = v14->m_scale.m_quad;
                v21 = _mm_xor_ps(v19, v14->m_rotation.m_vec.m_quad);
                v22 = _mm_rcp_ps(v20);
                v23 = _mm_shuffle_ps(v21, v21, 255);
                v24 = _mm_shuffle_ps(v21, v21, 201);
                v25 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v22)), v22), 4);
                v26 = _mm_mul_ps(v13[v10].m_translation.m_quad, v21);
                v27 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v21), _mm_mul_ps(v24, v16));
                v28 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                              _mm_shuffle_ps(v26, v26, 170)),
                            v21),
                          _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v23, v23), (__m128)xmmword_141A711B0), v16)),
                        _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v23));
                v15[v10].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v28, v28), _mm_xor_ps(v18, v41.m_quad));
                v29 = v13[v10].m_rotation.m_vec.m_quad;
                v30 = _mm_shuffle_ps(v13[v10].m_rotation.m_vec.m_quad, v29, 255);
                v31 = _mm_mul_ps(_mm_shuffle_ps(v13[v10].m_rotation.m_vec.m_quad, v29, 201), v21);
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
              }
              v3->m_boneFlags.m_data[v8] &= 0xFFFFFFFE;
            }
            v3->m_boneFlags.m_data[v8] |= 4u;
            v3->m_modelInSync.m_bool = 0;
          }
        }
        ++v8;
        ++v10;
      }
      while ( v8 < v9 );
      v5 = v44;
      v4 = v43;
      v7 = v42;
    }
    for ( i = v7; i < v9; ++i )
    {
      v38 = v3->m_boneFlags.m_data;
      v39 = v38[i];
      if ( v39 & 4 )
        v38[i] = v39 & 0xFFFFFFFB | 2;
    }
    v40 = &v3->m_modelPose.m_data[v5].m_translation;
    *v40 = v4->m_translation;
    v40[1] = v4->m_rotation.m_vec;
    v40[2] = v4->m_scale;
    v3->m_boneFlags.m_data[v5] = 1;
    v3->m_localInSync.m_bool = 0;
  }
}

// File Line: 579
// RVA: 0x1BC940
void __fastcall SkeletalPose::SetPositionMS(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixMS)
{
  SkeletalPose *v3; // rsi
  __int64 v4; // rbx
  hkaPose *v5; // rsi
  __int64 v6; // r8
  __int64 v7; // rcx
  int v8; // eax
  __int64 v9; // r13
  __int64 v10; // r14
  signed __int64 v11; // rbp
  __int64 v12; // rdx
  unsigned int *v13; // rcx
  hkQsTransformf *v14; // r12
  hkQsTransformf *v15; // r15
  hkQsTransformf *v16; // rdi
  __m128 v17; // xmm3
  __m128i v18; // xmm0
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
  hkQsTransformf *v37; // rax
  __int64 i; // rcx
  unsigned int *v39; // rdx
  unsigned int v40; // eax
  hkQuaternionf *v41; // rax
  hkQsTransformf v42; // [rsp+20h] [rbp-E8h]
  hkTransformf transform; // [rsp+50h] [rbp-B8h]

  if ( boneID >= 0 )
  {
    v3 = this;
    v4 = boneID;
    hkTransformf::set4x4ColumnMajor(&transform, &matrixMS->v0.x);
    hkQsTransformf::setFromTransformNoScale(&v42, &transform);
    v5 = v3->mHavokPose;
    v6 = v4;
    v7 = v5->m_skeleton->m_bones.m_size;
    v5->m_boneFlags.m_data[v4] |= 4u;
    v8 = v4 + 1;
    v9 = v7;
    v10 = (signed int)v4 + 1;
    if ( v10 < v7 )
    {
      v11 = v8;
      do
      {
        LOWORD(v12) = v5->m_skeleton->m_parentIndices.m_data[v10];
        if ( (_WORD)v12 != -1 )
        {
          v13 = v5->m_boneFlags.m_data;
          if ( v13[(signed __int16)v12] & 4 )
          {
            if ( v13[v10] & 1 )
            {
              v14 = v5->m_modelPose.m_data;
              if ( (_WORD)v12 == -1 )
              {
                v37 = v5->m_localPose.m_data;
                v37[v11].m_translation = v14[v11].m_translation;
                v37[v11].m_rotation = v14[v11].m_rotation;
                v37[v11].m_scale = v14[v11].m_scale;
              }
              else
              {
                v12 = (signed __int16)v12;
                if ( v13[(signed __int16)v12] & 2 )
                  v15 = hkaPose::calculateBoneModelSpace(v5, v12);
                else
                  v15 = &v14[v12];
                v16 = v5->m_localPose.m_data;
                hkVector4f::setRotatedInverseDir(&transform.m_rotation.m_col0, &v15->m_rotation, &v15->m_translation);
                v17 = v14[v11].m_translation.m_quad;
                v18 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
                v19 = (__m128)_mm_shuffle_epi32(v18, 0);
                v20 = (__m128)_mm_shuffle_epi32(v18, 64);
                v21 = v15->m_scale.m_quad;
                v22 = _mm_xor_ps(v20, v15->m_rotation.m_vec.m_quad);
                v23 = _mm_rcp_ps(v21);
                v24 = _mm_shuffle_ps(v22, v22, 255);
                v25 = _mm_shuffle_ps(v22, v22, 201);
                v26 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v21, v23)), v23), 4);
                v27 = _mm_mul_ps(v22, v17);
                v28 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v22), _mm_mul_ps(v25, v17));
                v29 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                              _mm_shuffle_ps(v27, v27, 170)),
                            v22),
                          _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v24, v24), (__m128)xmmword_141A711B0), v17)),
                        _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v24));
                v16[v11].m_translation.m_quad = _mm_add_ps(
                                                  _mm_add_ps(v29, v29),
                                                  _mm_xor_ps(v19, transform.m_rotation.m_col0.m_quad));
                v30 = v14[v11].m_rotation.m_vec.m_quad;
                v31 = _mm_shuffle_ps(v14[v11].m_rotation.m_vec.m_quad, v30, 255);
                v32 = _mm_mul_ps(_mm_shuffle_ps(v14[v11].m_rotation.m_vec.m_quad, v30, 201), v22);
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
              }
              v5->m_boneFlags.m_data[v10] &= 0xFFFFFFFE;
            }
            v5->m_boneFlags.m_data[v10] |= 4u;
            v5->m_modelInSync.m_bool = 0;
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
      v39 = v5->m_boneFlags.m_data;
      v40 = v39[i];
      if ( v40 & 4 )
        v39[i] = v40 & 0xFFFFFFFB | 2;
    }
    v41 = (hkQuaternionf *)&v5->m_modelPose.m_data[v6];
    *v41 = (hkQuaternionf)v42.m_translation;
    v41[1] = v42.m_rotation;
    v41[2] = (hkQuaternionf)v42.m_scale;
    v5->m_boneFlags.m_data[v6] = 1;
    v5->m_localInSync.m_bool = 0;
  }
}

// File Line: 594
// RVA: 0x1BCCD0
void __fastcall SkeletalPose::SetPositionMS_ReNormalize(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixMS)
{
  SkeletalPose *v3; // rsi
  __int64 v4; // rbx
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  hkaPose *v9; // rsi
  __int64 v10; // r8
  __int64 v11; // rcx
  int v12; // eax
  __int64 v13; // r13
  __int64 v14; // r14
  signed __int64 v15; // rbp
  __int64 v16; // rdx
  unsigned int *v17; // rcx
  hkQsTransformf *v18; // r12
  hkQsTransformf *v19; // r15
  hkQsTransformf *v20; // rdi
  __m128 v21; // xmm3
  __m128i v22; // xmm0
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
  hkQsTransformf *v41; // rax
  __int64 i; // rcx
  unsigned int *v43; // rdx
  unsigned int v44; // eax
  hkQuaternionf *v45; // rax
  hkQsTransformf v46; // [rsp+20h] [rbp-E8h]
  hkTransformf transform; // [rsp+50h] [rbp-B8h]

  if ( boneID >= 0 )
  {
    v3 = this;
    v4 = boneID;
    hkTransformf::set4x4ColumnMajor(&transform, &matrixMS->v0.x);
    hkQsTransformf::setFromTransformNoScale(&v46, &transform);
    if ( sNormalize )
    {
      v5 = _mm_mul_ps(v46.m_rotation.m_vec.m_quad, v46.m_rotation.m_vec.m_quad);
      v6 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 78), v5);
      v7 = _mm_add_ps(_mm_shuffle_ps(v6, v6, 177), v6);
      v8 = _mm_rsqrt_ps(v7);
      v46.m_scale = (hkVector4f)_xmm;
      v46.m_rotation.m_vec.m_quad = _mm_mul_ps(
                                      v46.m_rotation.m_vec.m_quad,
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)),
                                        _mm_mul_ps(*(__m128 *)_xmm, v8)));
    }
    v9 = v3->mHavokPose;
    v10 = v4;
    v11 = v9->m_skeleton->m_bones.m_size;
    v9->m_boneFlags.m_data[v4] |= 4u;
    v12 = v4 + 1;
    v13 = v11;
    v14 = (signed int)v4 + 1;
    if ( v14 < v11 )
    {
      v15 = v12;
      do
      {
        LOWORD(v16) = v9->m_skeleton->m_parentIndices.m_data[v14];
        if ( (_WORD)v16 != -1 )
        {
          v17 = v9->m_boneFlags.m_data;
          if ( v17[(signed __int16)v16] & 4 )
          {
            if ( v17[v14] & 1 )
            {
              v18 = v9->m_modelPose.m_data;
              if ( (_WORD)v16 == -1 )
              {
                v41 = v9->m_localPose.m_data;
                v41[v15].m_translation = v18[v15].m_translation;
                v41[v15].m_rotation = v18[v15].m_rotation;
                v41[v15].m_scale = v18[v15].m_scale;
              }
              else
              {
                v16 = (signed __int16)v16;
                if ( v17[(signed __int16)v16] & 2 )
                  v19 = hkaPose::calculateBoneModelSpace(v9, v16);
                else
                  v19 = &v18[v16];
                v20 = v9->m_localPose.m_data;
                hkVector4f::setRotatedInverseDir(&transform.m_rotation.m_col0, &v19->m_rotation, &v19->m_translation);
                v21 = v18[v15].m_translation.m_quad;
                v22 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
                v23 = (__m128)_mm_shuffle_epi32(v22, 0);
                v24 = (__m128)_mm_shuffle_epi32(v22, 64);
                v25 = v19->m_scale.m_quad;
                v26 = _mm_xor_ps(v24, v19->m_rotation.m_vec.m_quad);
                v27 = _mm_rcp_ps(v25);
                v28 = _mm_shuffle_ps(v26, v26, 255);
                v29 = _mm_shuffle_ps(v26, v26, 201);
                v30 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v25, v27)), v27), 4);
                v31 = _mm_mul_ps(v26, v21);
                v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v26), _mm_mul_ps(v29, v21));
                v33 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                              _mm_shuffle_ps(v31, v31, 170)),
                            v26),
                          _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v28, v28), (__m128)xmmword_141A711B0), v21)),
                        _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v28));
                v20[v15].m_translation.m_quad = _mm_add_ps(
                                                  _mm_add_ps(v33, v33),
                                                  _mm_xor_ps(v23, transform.m_rotation.m_col0.m_quad));
                v34 = v18[v15].m_rotation.m_vec.m_quad;
                v35 = _mm_shuffle_ps(v18[v15].m_rotation.m_vec.m_quad, v34, 255);
                v36 = _mm_mul_ps(_mm_shuffle_ps(v18[v15].m_rotation.m_vec.m_quad, v34, 201), v26);
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
              }
              v9->m_boneFlags.m_data[v14] &= 0xFFFFFFFE;
            }
            v9->m_boneFlags.m_data[v14] |= 4u;
            v9->m_modelInSync.m_bool = 0;
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
      v43 = v9->m_boneFlags.m_data;
      v44 = v43[i];
      if ( v44 & 4 )
        v43[i] = v44 & 0xFFFFFFFB | 2;
    }
    v45 = (hkQuaternionf *)&v9->m_modelPose.m_data[v10];
    *v45 = (hkQuaternionf)v46.m_translation;
    v45[1] = v46.m_rotation;
    v45[2] = (hkQuaternionf)v46.m_scale;
    v9->m_boneFlags.m_data[v10] = 1;
    v9->m_localInSync.m_bool = 0;
  }
}

// File Line: 619
// RVA: 0x1BB790
void __fastcall SkeletalPose::GetPositionLS(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixLS)
{
  hkaPose *v3; // r14
  __int64 v4; // r15
  UFG::qMatrix44 *v5; // r13
  unsigned int *v6; // r9
  hkQsTransformf *v7; // rcx
  signed __int64 v8; // rsi
  __int16 v9; // ax
  hkQsTransformf *v10; // r12
  hkQsTransformf *v11; // rbp
  hkQsTransformf *v12; // rdi
  __m128 v13; // xmm3
  __m128i v14; // xmm0
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
  hkVector4f v34; // [rsp+20h] [rbp-98h]

  v3 = this->mHavokPose;
  v4 = boneID;
  v5 = matrixLS;
  v6 = v3->m_boneFlags.m_data;
  if ( v6[boneID] & 1 )
  {
    v8 = boneID;
    v9 = v3->m_skeleton->m_parentIndices.m_data[boneID];
    v10 = v3->m_modelPose.m_data;
    if ( v9 == -1 )
    {
      v33 = v3->m_localPose.m_data;
      v33[v8].m_translation = v10[v8].m_translation;
      v33[v8].m_rotation = v10[v8].m_rotation;
      v33[v8].m_scale = v10[v8].m_scale;
    }
    else
    {
      if ( v6[v9] & 2 )
        v11 = hkaPose::calculateBoneModelSpace(v3, v9);
      else
        v11 = &v10[v9];
      v12 = v3->m_localPose.m_data;
      hkVector4f::setRotatedInverseDir(&v34, &v11->m_rotation, &v11->m_translation);
      v13 = v10[v8].m_translation.m_quad;
      v14 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v15 = (__m128)_mm_shuffle_epi32(v14, 0);
      v16 = (__m128)_mm_shuffle_epi32(v14, 64);
      v17 = v11->m_scale.m_quad;
      v18 = _mm_xor_ps(v16, v11->m_rotation.m_vec.m_quad);
      v19 = _mm_rcp_ps(v17);
      v20 = _mm_shuffle_ps(v18, v18, 255);
      v21 = _mm_shuffle_ps(v18, v18, 201);
      v22 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v19)), v19), 4);
      v23 = _mm_mul_ps(v10[v8].m_translation.m_quad, v18);
      v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v18), _mm_mul_ps(v21, v13));
      v25 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                    _mm_shuffle_ps(v23, v23, 170)),
                  v18),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v20, v20), (__m128)xmmword_141A711B0), v13)),
              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v20));
      v12[v8].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v25, v25), _mm_xor_ps(v15, v34.m_quad));
      v26 = v10[v8].m_rotation.m_vec.m_quad;
      v27 = _mm_shuffle_ps(v10[v8].m_rotation.m_vec.m_quad, v26, 255);
      v28 = _mm_mul_ps(_mm_shuffle_ps(v10[v8].m_rotation.m_vec.m_quad, v26, 201), v18);
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
    v3->m_boneFlags.m_data[v4] &= 0xFFFFFFFE;
    v7 = &v3->m_localPose.m_data[v8];
  }
  else
  {
    v7 = &v3->m_localPose.m_data[boneID];
  }
  hkQsTransformf::get4x4ColumnMajor(v7, &v5->v0.x);
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
  hkQsTransformf *v3; // rdx
  hkQsTransformf v4; // [rsp+20h] [rbp-38h]

  v3 = &this->mHavokPose->m_skeleton->m_referencePose.m_data[boneID];
  v4.m_translation = v3->m_translation;
  v4.m_rotation = v3->m_rotation;
  v4.m_scale = v3->m_scale;
  hkQsTransformf::get4x4ColumnMajor(&v4, &matrixRS->v0.x);
}

// File Line: 653
// RVA: 0x1BC5B0
void __fastcall SkeletalPose::SetPositionLS(SkeletalPose *this, int boneID, UFG::qMatrix44 *matrixLS)
{
  SkeletalPose *v3; // rsi
  __int64 v4; // rbx
  hkaPose *v5; // rsi
  __int64 v6; // r8
  __int64 v7; // rcx
  int v8; // eax
  __int64 v9; // r13
  __int64 v10; // r14
  signed __int64 v11; // rbp
  __int64 v12; // rdx
  unsigned int *v13; // rcx
  hkQsTransformf *v14; // r12
  hkQsTransformf *v15; // r15
  hkQsTransformf *v16; // rdi
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128i v19; // xmm0
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
  hkQsTransformf *v34; // rax
  __int64 i; // rcx
  unsigned int *v36; // rdx
  unsigned int v37; // eax
  hkQuaternionf *v38; // rax
  hkQsTransformf v39; // [rsp+20h] [rbp-E8h]
  hkTransformf transform; // [rsp+50h] [rbp-B8h]

  if ( boneID >= 0 )
  {
    v3 = this;
    v4 = boneID;
    hkTransformf::set4x4ColumnMajor(&transform, &matrixLS->v0.x);
    hkQsTransformf::setFromTransformNoScale(&v39, &transform);
    v5 = v3->mHavokPose;
    v6 = v4;
    v7 = v5->m_skeleton->m_bones.m_size;
    v5->m_boneFlags.m_data[v4] |= 4u;
    v8 = v4 + 1;
    v9 = v7;
    v10 = (signed int)v4 + 1;
    if ( v10 < v7 )
    {
      v11 = v8;
      do
      {
        LOWORD(v12) = v5->m_skeleton->m_parentIndices.m_data[v10];
        if ( (_WORD)v12 != -1 )
        {
          v13 = v5->m_boneFlags.m_data;
          if ( v13[(signed __int16)v12] & 4 )
          {
            if ( v13[v10] & 1 )
            {
              v14 = v5->m_modelPose.m_data;
              if ( (_WORD)v12 == -1 )
              {
                v34 = v5->m_localPose.m_data;
                v34[v11].m_translation = v14[v11].m_translation;
                v34[v11].m_rotation = v14[v11].m_rotation;
                v34[v11].m_scale = v14[v11].m_scale;
              }
              else
              {
                v12 = (signed __int16)v12;
                if ( v13[(signed __int16)v12] & 2 )
                  v15 = hkaPose::calculateBoneModelSpace(v5, v12);
                else
                  v15 = &v14[v12];
                v16 = v5->m_localPose.m_data;
                hkVector4f::setRotatedInverseDir(&transform.m_rotation.m_col0, &v15->m_rotation, &v15->m_translation);
                v17 = v14[v11].m_translation.m_quad;
                v18 = _mm_rcp_ps(v15->m_scale.m_quad);
                v19 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
                v20 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v19, 64), v15->m_rotation.m_vec.m_quad);
                v21 = (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v15->m_scale.m_quad)),
                                             v18),
                                  4),
                                4);
                v22 = _mm_mul_ps(v14[v11].m_translation.m_quad, v20);
                v23 = _mm_shuffle_ps(v20, v20, 255);
                v24 = _mm_shuffle_ps(v20, v20, 201);
                v25 = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v20),
                        _mm_mul_ps(v14[v11].m_translation.m_quad, v24));
                v26 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                              _mm_shuffle_ps(v22, v22, 170)),
                            v20),
                          _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v23, v23), (__m128)xmmword_141A711B0), v17)),
                        _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v23));
                v16[v11].m_translation.m_quad = _mm_add_ps(
                                                  _mm_add_ps(v26, v26),
                                                  _mm_xor_ps(
                                                    (__m128)_mm_shuffle_epi32(v19, 0),
                                                    transform.m_rotation.m_col0.m_quad));
                v27 = v14[v11].m_rotation.m_vec.m_quad;
                v28 = _mm_shuffle_ps(v14[v11].m_rotation.m_vec.m_quad, v27, 255);
                v29 = _mm_mul_ps(_mm_shuffle_ps(v14[v11].m_rotation.m_vec.m_quad, v27, 201), v20);
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
              }
              v5->m_boneFlags.m_data[v10] &= 0xFFFFFFFE;
            }
            v5->m_boneFlags.m_data[v10] |= 4u;
            v5->m_modelInSync.m_bool = 0;
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
      v36 = v5->m_boneFlags.m_data;
      v37 = v36[i];
      if ( v37 & 4 )
        v36[i] = v37 & 0xFFFFFFFB | 2;
    }
    v38 = (hkQuaternionf *)&v5->m_localPose.m_data[v6];
    *v38 = (hkQuaternionf)v39.m_translation;
    v38[1] = v39.m_rotation;
    v38[2] = (hkQuaternionf)v39.m_scale;
    v5->m_boneFlags.m_data[v6] = 2;
    v5->m_modelInSync.m_bool = 0;
  }
}

// File Line: 676
// RVA: 0x1BDBA0
void __fastcall SkeletalPose::SetQsTransformLS(SkeletalPose *this, int boneID, hkQsTransformf *matrixLS)
{
  hkaPose *v3; // rsi
  hkQsTransformf *v4; // r9
  __int64 v5; // r8
  __int64 v6; // rcx
  int v7; // eax
  __int64 v8; // r14
  __int64 v9; // r13
  signed __int64 v10; // rbp
  __int64 v11; // rdx
  unsigned int *v12; // rcx
  hkQsTransformf *v13; // r12
  hkQsTransformf *v14; // r15
  hkQsTransformf *v15; // rdi
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128i v18; // xmm0
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
  hkQsTransformf *v33; // rax
  __int64 i; // rcx
  unsigned int *v35; // rdx
  unsigned int v36; // eax
  hkVector4f *v37; // rax
  hkVector4f v38; // [rsp+20h] [rbp-A8h]
  int v39; // [rsp+D8h] [rbp+10h]
  hkQsTransformf *v40; // [rsp+E0h] [rbp+18h]
  __int64 v41; // [rsp+E8h] [rbp+20h]

  if ( boneID >= 0 )
  {
    v40 = matrixLS;
    v3 = this->mHavokPose;
    v4 = matrixLS;
    v5 = boneID;
    v6 = v3->m_skeleton->m_bones.m_size;
    v3->m_boneFlags.m_data[boneID] |= 4u;
    v7 = boneID + 1;
    v41 = boneID;
    v8 = boneID + 1;
    v39 = boneID + 1;
    v9 = v6;
    if ( v8 < v6 )
    {
      v10 = v7;
      do
      {
        LOWORD(v11) = v3->m_skeleton->m_parentIndices.m_data[v8];
        if ( (_WORD)v11 != -1 )
        {
          v12 = v3->m_boneFlags.m_data;
          if ( v12[(signed __int16)v11] & 4 )
          {
            if ( v12[v8] & 1 )
            {
              v13 = v3->m_modelPose.m_data;
              if ( (_WORD)v11 == -1 )
              {
                v33 = v3->m_localPose.m_data;
                v33[v10].m_translation = v13[v10].m_translation;
                v33[v10].m_rotation = v13[v10].m_rotation;
                v33[v10].m_scale = v13[v10].m_scale;
              }
              else
              {
                v11 = (signed __int16)v11;
                if ( v12[(signed __int16)v11] & 2 )
                  v14 = hkaPose::calculateBoneModelSpace(v3, v11);
                else
                  v14 = &v13[v11];
                v15 = v3->m_localPose.m_data;
                hkVector4f::setRotatedInverseDir(&v38, &v14->m_rotation, &v14->m_translation);
                v16 = v13[v10].m_translation.m_quad;
                v17 = _mm_rcp_ps(v14->m_scale.m_quad);
                v18 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
                v19 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v18, 64), v14->m_rotation.m_vec.m_quad);
                v20 = (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v14->m_scale.m_quad)),
                                             v17),
                                  4),
                                4);
                v21 = _mm_mul_ps(v13[v10].m_translation.m_quad, v19);
                v22 = _mm_shuffle_ps(v19, v19, 255);
                v23 = _mm_shuffle_ps(v19, v19, 201);
                v24 = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v19),
                        _mm_mul_ps(v13[v10].m_translation.m_quad, v23));
                v25 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                              _mm_shuffle_ps(v21, v21, 170)),
                            v19),
                          _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v22, v22), (__m128)xmmword_141A711B0), v16)),
                        _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v22));
                v15[v10].m_translation.m_quad = _mm_add_ps(
                                                  _mm_add_ps(v25, v25),
                                                  _mm_xor_ps((__m128)_mm_shuffle_epi32(v18, 0), v38.m_quad));
                v26 = v13[v10].m_rotation.m_vec.m_quad;
                v27 = _mm_shuffle_ps(v13[v10].m_rotation.m_vec.m_quad, v26, 255);
                v28 = _mm_mul_ps(_mm_shuffle_ps(v13[v10].m_rotation.m_vec.m_quad, v26, 201), v19);
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
              }
              v3->m_boneFlags.m_data[v8] &= 0xFFFFFFFE;
            }
            v3->m_boneFlags.m_data[v8] |= 4u;
            v3->m_modelInSync.m_bool = 0;
          }
        }
        ++v8;
        ++v10;
      }
      while ( v8 < v9 );
      v5 = v41;
      v4 = v40;
      v7 = v39;
    }
    for ( i = v7; i < v9; ++i )
    {
      v35 = v3->m_boneFlags.m_data;
      v36 = v35[i];
      if ( v36 & 4 )
        v35[i] = v36 & 0xFFFFFFFB | 2;
    }
    v37 = &v3->m_localPose.m_data[v5].m_translation;
    *v37 = v4->m_translation;
    v37[1] = v4->m_rotation.m_vec;
    v37[2] = v4->m_scale;
    v3->m_boneFlags.m_data[v5] = 2;
    v3->m_modelInSync.m_bool = 0;
  }
}

// File Line: 690
// RVA: 0x1BACB0
int SkeletalPose::DebugDraw(...)
{
  UFG::qColour *v3; // rbx
  SkeletalPose *v4; // rsi
  Skeleton *v5; // rdi
  hkaSkeleton *v6; // r14
  unsigned int v7; // er9
  unsigned int v8; // er8
  bool *v9; // rcx
  unsigned int *v10; // rdi
  unsigned int v11; // er10
  unsigned int v12; // er11
  unsigned int v13; // ebx
  bool v14; // r14
  unsigned int v15; // er15
  bool v16; // dl
  unsigned int v17; // er12
  unsigned int v18; // er13
  unsigned int v19; // eax
  __m128 v20; // xmm1
  _QWORD **v21; // rax
  __int64 v22; // rax
  hkaPose *v23; // rbx
  int v24; // edi
  int v25; // esi
  int v26; // eax
  int v27; // eax
  int v28; // er9
  int v29; // eax
  int v30; // eax
  int v31; // er9
  int v32; // eax
  int v33; // eax
  int v34; // er9
  int v35; // esi
  int v36; // er9
  int v37; // eax
  int v38; // eax
  int v39; // er9
  int v40; // edx
  float *v41; // rdi
  __int64 v42; // rcx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v43; // rax
  __int64 v44; // rdi
  __m128 v45; // xmm1
  __int64 v46; // rdx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v47; // rax
  _QWORD **v48; // rax
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v49; // rax
  hkResult v50; // [rsp+30h] [rbp-D0h]
  hkResult v51; // [rsp+34h] [rbp-CCh]
  hkResult v52; // [rsp+38h] [rbp-C8h]
  hkResult v53; // [rsp+3Ch] [rbp-C4h]
  hkResult v54; // [rsp+40h] [rbp-C0h]
  hkResult v55; // [rsp+44h] [rbp-BCh]
  hkaSkeleton *skeleton; // [rsp+48h] [rbp-B8h]
  __int64 v57; // [rsp+50h] [rbp-B0h]
  __int64 v58; // [rsp+58h] [rbp-A8h]
  hkTransformf transform; // [rsp+60h] [rbp-A0h]
  bool boneDraw; // [rsp+A0h] [rbp-60h]
  SkeletalPose *v61; // [rsp+1B0h] [rbp+B0h]
  UFG::qColour *coloura; // [rsp+1B8h] [rbp+B8h]
  hkResult result; // [rsp+1C0h] [rbp+C0h]
  hkResult v64; // [rsp+1C8h] [rbp+C8h]

  coloura = colour;
  v61 = this;
  v58 = -2i64;
  v3 = colour;
  v4 = this;
  SkeletalPose::syncTransformToRoot(this);
  v5 = v4->mRigHandle.mUFGSkeleton;
  v6 = v4->mHavokPose->m_skeleton;
  skeleton = v6;
  v7 = v6->m_bones.m_size;
  v8 = 0;
  if ( v7 )
  {
    v9 = &boneDraw;
    v10 = v5->mBoneNameHashIDs;
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
      v19 = *v10;
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
      ++v10;
      ++v9;
    }
    while ( v8 < v7 );
    v6 = skeleton;
    v3 = coloura;
  }
  v20 = (__m128)fScale;
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
    v49 = hkaPose::getSyncedPoseModelSpace(v4->mHavokPose);
    DrawBoneHavok(v6, v49->m_data, &v4->mRootQsMatrix, &boneDraw, v3);
  }
  else
  {
    v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(v21[11], 80i64);
    v23 = (hkaPose *)v22;
    v57 = v22;
    if ( v22 )
    {
      *(_QWORD *)v22 = v6;
      *(_QWORD *)(v22 + 8) = 0i64;
      *(_DWORD *)(v22 + 16) = 0;
      *(_DWORD *)(v22 + 20) = 2147483648;
      *(_QWORD *)(v22 + 24) = 0i64;
      *(_DWORD *)(v22 + 32) = 0;
      *(_DWORD *)(v22 + 36) = 2147483648;
      *(_QWORD *)(v22 + 40) = 0i64;
      *(_DWORD *)(v22 + 48) = 0;
      *(_DWORD *)(v22 + 52) = 2147483648;
      *(_WORD *)(v22 + 56) = 0;
      *(_QWORD *)(v22 + 64) = 0i64;
      *(_DWORD *)(v22 + 72) = 0;
      *(_DWORD *)(v22 + 76) = 2147483648;
      v24 = *(_DWORD *)(*(_QWORD *)v22 + 48i64);
      v25 = (v24 + 3) & 0xFFFFFFFC;
      if ( (*(_DWORD *)(v22 + 36) & 0x3FFFFFFF) >= v25 )
        result.m_enum = 0;
      else
        hkArrayUtil::_reserve(
          &result,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          (void *)(v22 + 24),
          v25,
          48);
      if ( (v23->m_localPose.m_capacityAndFlags & 0x3FFFFFFF) >= v25 )
        v64.m_enum = 0;
      else
        hkArrayUtil::_reserve(
          &v64,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v23->m_localPose,
          v25,
          48);
      if ( (v23->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) >= v25 )
        v51.m_enum = 0;
      else
        hkArrayUtil::_reserve(
          &v51,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v23->m_boneFlags,
          v25,
          4);
      v26 = v23->m_modelPose.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v26 >= v24 )
      {
        v55.m_enum = 0;
      }
      else
      {
        v27 = 2 * v26;
        v28 = v24;
        if ( v24 < v27 )
          v28 = v27;
        hkArrayUtil::_reserve(
          &v55,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v23->m_modelPose,
          v28,
          48);
      }
      v23->m_modelPose.m_size = v24;
      v29 = v23->m_localPose.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v29 >= v24 )
      {
        v54.m_enum = 0;
      }
      else
      {
        v30 = 2 * v29;
        v31 = v24;
        if ( v24 < v30 )
          v31 = v30;
        hkArrayUtil::_reserve(
          &v54,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v23->m_localPose,
          v31,
          48);
      }
      v23->m_localPose.m_size = v24;
      v32 = v23->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v32 >= v24 )
      {
        v52.m_enum = 0;
      }
      else
      {
        v33 = 2 * v32;
        v34 = v24;
        if ( v24 < v33 )
          v34 = v33;
        hkArrayUtil::_reserve(
          &v52,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v23->m_boneFlags,
          v34,
          4);
      }
      v23->m_boneFlags.m_size = v24;
      v35 = v23->m_skeleton->m_floatSlots.m_size;
      v36 = (v35 + 3) & 0xFFFFFFFC;
      if ( (v23->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) >= v36 )
        v53.m_enum = 0;
      else
        hkArrayUtil::_reserve(
          &v53,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v23->m_floatSlotValues,
          v36,
          4);
      v37 = v23->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v37 >= v35 )
      {
        v50.m_enum = 0;
      }
      else
      {
        v38 = 2 * v37;
        v39 = v35;
        if ( v35 < v38 )
          v39 = v38;
        hkArrayUtil::_reserve(
          &v50,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v23->m_floatSlotValues,
          v39,
          4);
      }
      v40 = v35 - v23->m_floatSlotValues.m_size;
      v41 = &v23->m_floatSlotValues.m_data[v23->m_floatSlotValues.m_size];
      v42 = v40;
      if ( v40 > 0 )
      {
        while ( v42 )
        {
          *v41 = 0.0;
          ++v41;
          --v42;
        }
      }
      v23->m_floatSlotValues.m_size = v35;
      v4 = v61;
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
    DrawBoneHavok(skeleton, v47->m_data, &v4->mRootQsMatrix, &boneDraw, coloura);
    if ( v23 )
    {
      hkaPose::~hkaPose(v23);
      v48 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkaPose *, signed __int64))(*v48[11] + 16i64))(v48[11], v23, 80i64);
    }
  }
}

// File Line: 796
// RVA: 0x1BE590
void __usercall blendPosehkQ(hkQsTransformf *poseLocalSpaceOutAcc@<rcx>, hkQsTransformf *posePose@<rdx>, unsigned int numBones@<r8d>, float weight@<xmm3>, __m128 a5@<xmm4>, __m128 a6@<xmm5>, const float *perBoneWeights, __int16 *transformTrackToBoneIndices)
{
  signed int v8; // eax
  __int64 v9; // r9
  __int64 v10; // r11
  hkQuaternionf *v11; // rax
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
  signed __int64 v25; // r9
  __m128 v26; // xmm1
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  __m128 v29; // xmm4
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm2

  v8 = numBones - 1;
  v9 = (signed int)(numBones - 1);
  if ( perBoneWeights )
  {
    v10 = 0i64;
    if ( v8 >= 0 )
    {
      v11 = &poseLocalSpaceOutAcc->m_rotation;
      v12 = (char *)posePose - (char *)poseLocalSpaceOutAcc;
      do
      {
        v13 = perBoneWeights[v10];
        v14 = *(__m128 *)((char *)&v11[1].m_vec.m_quad + v12);
        ++v10;
        v11 += 3;
        a5.m128_f32[0] = (float)(v13 * 0.0039215689) * weight;
        a5 = _mm_shuffle_ps(a5, a5, 0);
        v11[-2].m_vec.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v14, v11[-2].m_vec.m_quad), a5), v11[-2].m_vec.m_quad);
        v11[-4].m_vec.m_quad = _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_sub_ps(*(__m128 *)((char *)&v11[-4].m_vec.m_quad + v12), v11[-4].m_vec.m_quad),
                                   a5),
                                 v11[-4].m_vec.m_quad);
        v15 = _mm_mul_ps(*(__m128 *)((char *)&v11[-3].m_vec.m_quad + v12), v11[-3].m_vec.m_quad);
        v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
        v17 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_xor_ps(
                    (__m128)_mm_slli_epi32(
                              _mm_srli_epi32(
                                (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16), (__m128)0i64),
                                0x1Fu),
                              0x1Fu),
                    a5),
                  *(__m128 *)((char *)&v11[-3].m_vec.m_quad + v12)),
                _mm_mul_ps(_mm_sub_ps(query.m_quad, a5), v11[-3].m_vec.m_quad));
        v18 = _mm_mul_ps(v17, v17);
        v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
        v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
        v21 = _mm_rsqrt_ps(v20);
        v11[-3].m_vec.m_quad = _mm_mul_ps(
                                 v17,
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                   _mm_mul_ps(*(__m128 *)_xmm, v21)));
        v11[-2] = (hkQuaternionf)_xmm;
      }
      while ( v10 <= v9 );
    }
  }
  else if ( v8 >= 0 )
  {
    a6.m128_f32[0] = weight;
    v22 = (char *)posePose - (char *)poseLocalSpaceOutAcc;
    v23 = &poseLocalSpaceOutAcc->m_rotation;
    v24 = _mm_shuffle_ps(a6, a6, 0);
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
                              (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v28, v28, 177), v28), (__m128)0i64),
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
void __usercall SkeletalPose::Blend(SkeletalPose *this@<rcx>, SkeletalPose *inputPose@<rdx>, float weight@<xmm2>, int boneCountMaxLOD@<r9d>, __int128 a5@<xmm7>, bool applyAllTransforms, float *weightset_array)
{
  int v7; // er14
  SkeletalPose *v8; // rsi
  SkeletalPose *v9; // rdi
  hkQsTransformf *v10; // rbx
  hkQsTransformf *v11; // r10
  unsigned int v12; // er9
  signed __int64 v13; // rax
  signed __int64 v14; // rbx
  __int64 v15; // rcx
  __int128 v16; // xmm0
  hkaSkeleton *v17; // r11
  signed __int64 v18; // rbx
  signed __int64 v19; // rdx
  signed __int64 v20; // r15
  __int64 v21; // r10
  __int64 v22; // r8
  __int128 v23; // xmm0
  __int128 v24; // xmm1
  UFG::qVector4 v25; // xmm1
  UFG::qVector4 v26; // xmm0
  UFG::qVector4 v27; // xmm1
  Render::DebugDrawContext *v28; // rax
  UFG::TransformNodeComponent *v29; // rcx
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
  hkVector4f v41; // xmm1
  hkVector4f v42; // xmm0
  hkVector4f v43; // xmm1
  Render::DebugDrawContext *v44; // rax
  UFG::qVector4 v45; // xmm1
  __m128 v46; // xmm7
  UFG::qVector4 v47; // xmm0
  UFG::qVector4 v48; // xmm6
  __m128 v49; // xmm0
  UFG::qVector4 v50; // xmm5
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
  UFG::qMatrix44 xform; // [rsp+18h] [rbp-69h]
  hkTransformf transform; // [rsp+58h] [rbp-29h]
  char v63; // [rsp+F8h] [rbp+77h]
  float *perBoneWeights; // [rsp+100h] [rbp+7Fh]

  v7 = boneCountMaxLOD;
  v8 = inputPose;
  v9 = this;
  if ( weight == 1.0 )
  {
    v10 = hkaPose::getSyncedPoseLocalSpace(inputPose->mHavokPose)->m_data;
    v11 = hkaPose::accessUnsyncedPoseLocalSpace(v9->mHavokPose)->m_data;
    v12 = v8->mHavokPose->m_skeleton->m_bones.m_size;
    if ( v7 >= 0 && v7 < v12 )
      v12 = v7;
    if ( v63 )
    {
      if ( v12 )
      {
        v13 = (signed __int64)&v11->m_rotation;
        v14 = (char *)v10 - (char *)v11;
        v15 = v12;
        do
        {
          v16 = *(_OWORD *)(v14 + v13 - 16);
          v13 += 48i64;
          *(_OWORD *)(v13 - 64) = v16;
          *(_OWORD *)(v13 - 48) = *(_OWORD *)(v14 + v13 - 48);
          *(_OWORD *)(v13 - 32) = *(_OWORD *)(v14 + v13 - 32);
          --v15;
        }
        while ( v15 );
      }
    }
    else
    {
      v17 = v9->mRigHandle.mUFGSkeleton->mhkaSkeleton;
      if ( v12 )
      {
        v18 = (char *)v10 - (char *)v11;
        v19 = (signed __int64)&v11->m_rotation;
        v20 = -16i64 - (_QWORD)v11;
        v21 = v12;
        v22 = 0i64;
        do
        {
          if ( v17->m_bones.m_data[v22].m_lockTranslation.m_bool )
            v23 = *(__int128 *)((char *)&v17->m_referencePose.m_data->m_translation + v20 + v19);
          else
            v23 = *(_OWORD *)(v19 + v18 - 16);
          *(_OWORD *)(v19 - 16) = v23;
          v24 = *(_OWORD *)(v19 + v18);
          v19 += 48i64;
          ++v22;
          *(_OWORD *)(v19 - 48) = v24;
          *(_OWORD *)(v19 - 32) = *(_OWORD *)(v19 + v18 - 32);
          --v21;
        }
        while ( v21 );
      }
    }
    if ( sShowCoordBefore )
    {
      SkeletalPose::syncTransformToRoot(v9);
      v25 = v9->mRootMatrix44.v1;
      xform.v0 = v9->mRootMatrix44.v0;
      v26 = v9->mRootMatrix44.v2;
      xform.v1 = v25;
      v27 = v9->mRootMatrix44.v3;
      xform.v2 = v26;
      xform.v3 = v27;
      v28 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      Render::DebugDrawContext::DrawCoord(v28, &xform, 0.25, 0i64);
    }
    SkeletalPose::syncTransformToRoot(v8);
    if ( v8->mIsRootDirty )
    {
      hkTransformf::set4x4ColumnMajor(&transform, &v8->mRootMatrix44.v0.x);
      hkQsTransformf::setFromTransformNoScale(&v8->mRootQsMatrix, &transform);
      v8->mIsRootDirty = 0;
    }
    v9->mRootQsMatrix.m_translation = v8->mRootQsMatrix.m_translation;
    v9->mRootQsMatrix.m_rotation = v8->mRootQsMatrix.m_rotation;
    v9->mRootQsMatrix.m_scale = v8->mRootQsMatrix.m_scale;
    hkQsTransformf::get4x4ColumnMajor(&v8->mRootQsMatrix, &v9->mRootMatrix44.v0.x);
    v29 = (UFG::TransformNodeComponent *)v9->mRootTransformNode.m_pPointer;
    v9->mIsRootDirty = 0;
    if ( v29 )
      UFG::TransformNodeComponent::SetWorldTransform(v29, &v9->mRootMatrix44);
    if ( sShowCoordAfter )
    {
      SkeletalPose::syncTransformToRoot(v9);
      v30 = v9->mRootMatrix44.v1;
      xform.v0 = v9->mRootMatrix44.v0;
      v31 = v9->mRootMatrix44.v2;
      xform.v1 = v30;
      v32 = v9->mRootMatrix44.v3;
      xform.v2 = v31;
      xform.v3 = v32;
      v33 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      Render::DebugDrawContext::DrawCoord(v33, &xform, 0.25, 0i64);
    }
  }
  else if ( weight > 0.0 )
  {
    v34 = hkaPose::getSyncedPoseLocalSpace(inputPose->mHavokPose)->m_data;
    v35 = hkaPose::accessUnsyncedPoseLocalSpace(v9->mHavokPose)->m_data;
    v36 = v8->mHavokPose->m_skeleton->m_bones.m_size;
    if ( v7 >= 0 && v7 < v36 )
      v36 = v7;
    blendPosehkQ(v35, v34, v36, weight, perBoneWeights, 0i64);
    if ( !v63 )
    {
      v37 = v9->mRigHandle.mUFGSkeleton->mhkaSkeleton;
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
      SkeletalPose::syncTransformToRoot(v9);
      v41.m_quad = (__m128)v9->mRootMatrix44.v1;
      transform.m_rotation.m_col0 = (hkVector4f)v9->mRootMatrix44.v0;
      v42.m_quad = (__m128)v9->mRootMatrix44.v2;
      transform.m_rotation.m_col1 = (hkVector4f)v41.m_quad;
      v43.m_quad = (__m128)v9->mRootMatrix44.v3;
      transform.m_rotation.m_col2 = (hkVector4f)v42.m_quad;
      transform.m_translation = (hkVector4f)v43.m_quad;
      v44 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      Render::DebugDrawContext::DrawCoord(v44, (UFG::qMatrix44 *)&transform, 0.25, 0i64);
    }
    SkeletalPose::syncTransformToRoot(v9);
    if ( v9->mIsRootDirty )
    {
      hkTransformf::set4x4ColumnMajor(&transform, &v9->mRootMatrix44.v0.x);
      hkQsTransformf::setFromTransformNoScale(&v9->mRootQsMatrix, &transform);
      v9->mIsRootDirty = 0;
    }
    v45 = (UFG::qVector4)v9->mRootQsMatrix.m_rotation;
    *(float *)&a5 = weight;
    v46 = _mm_shuffle_ps((__m128)a5, (__m128)a5, 0);
    xform.v0 = (UFG::qVector4)v9->mRootQsMatrix.m_translation;
    v47 = (UFG::qVector4)v9->mRootQsMatrix.m_scale;
    xform.v1 = v45;
    xform.v2 = v47;
    SkeletalPose::syncTransformToRoot(v8);
    if ( v8->mIsRootDirty )
    {
      hkTransformf::set4x4ColumnMajor(&transform, &v8->mRootMatrix44.v0.x);
      hkQsTransformf::setFromTransformNoScale(&v8->mRootQsMatrix, &transform);
      v8->mIsRootDirty = 0;
    }
    v48 = (UFG::qVector4)_mm_add_ps(
                           (__m128)xform.v2,
                           _mm_mul_ps(_mm_sub_ps(v8->mRootQsMatrix.m_scale.m_quad, (__m128)xform.v2), v46));
    v49 = _mm_sub_ps(v8->mRootQsMatrix.m_translation.m_quad, (__m128)xform.v0);
    xform.v2 = v48;
    v50 = (UFG::qVector4)_mm_add_ps((__m128)xform.v0, _mm_mul_ps(v49, v46));
    v51 = _mm_mul_ps((__m128)xform.v1, v8->mRootQsMatrix.m_rotation.m_vec.m_quad);
    xform.v0 = v50;
    v52 = _mm_add_ps(_mm_shuffle_ps(v51, v51, 78), v51);
    v53 = _mm_mul_ps(_mm_sub_ps(query.m_quad, v46), (__m128)xform.v1);
    v54 = _mm_mul_ps(
            _mm_xor_ps(
              (__m128)_mm_slli_epi32(
                        _mm_srli_epi32(
                          (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v52, v52, 177), v52), (__m128)0i64),
                          0x1Fu),
                        0x1Fu),
              v46),
            v8->mRootQsMatrix.m_rotation.m_vec.m_quad);
    v9->mRootQsMatrix.m_translation = (hkVector4f)v50;
    v9->mRootQsMatrix.m_scale = (hkVector4f)v48;
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
    v9->mRootQsMatrix.m_rotation = (hkQuaternionf)xform.v1;
    hkQsTransformf::get4x4ColumnMajor((hkQsTransformf *)&xform, &v9->mRootMatrix44.v0.x);
    v60 = (UFG::TransformNodeComponent *)v9->mRootTransformNode.m_pPointer;
    v9->mIsRootDirty = 0;
    if ( v60 )
      UFG::TransformNodeComponent::SetWorldTransform(v60, &v9->mRootMatrix44);
  }
}

// File Line: 935
// RVA: 0x1BC1D0
void __fastcall SkeletalPose::RigLoadedCallback(UFG::RigHandle *handle, void *userData)
{
  UFG::qResourceData *v2; // rsi
  signed __int64 v3; // rbx
  char v4; // di
  __int64 v5; // rax
  char v6; // cl
  _QWORD **v7; // rax
  __int64 v8; // rax
  _DWORD *v9; // r14
  int v10; // edi
  int v11; // ebp
  int v12; // eax
  int v13; // eax
  int v14; // er9
  int v15; // eax
  int v16; // eax
  int v17; // er9
  int v18; // eax
  int v19; // eax
  int v20; // er9
  int v21; // ebp
  int v22; // er9
  int v23; // eax
  int v24; // eax
  int v25; // er9
  int v26; // edx
  _DWORD *v27; // rdi
  __int64 v28; // rcx
  char v29; // al
  hkResult v30; // [rsp+30h] [rbp-78h]
  hkResult v31; // [rsp+34h] [rbp-74h]
  hkResult v32; // [rsp+38h] [rbp-70h]
  hkResult v33; // [rsp+3Ch] [rbp-6Ch]
  hkResult v34; // [rsp+40h] [rbp-68h]
  __int64 v35; // [rsp+48h] [rbp-60h]
  __int64 v36; // [rsp+50h] [rbp-58h]
  hkResult result; // [rsp+B0h] [rbp+8h]
  _QWORD *v38; // [rsp+B8h] [rbp+10h]
  hkResult v39; // [rsp+C0h] [rbp+18h]
  hkResult v40; // [rsp+C8h] [rbp+20h]

  v38 = userData;
  v35 = -2i64;
  v2 = handle->mData;
  v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v4 = ++*(_BYTE *)(v3 + 80);
  v5 = v4;
  *(_DWORD *)(v3 + 4 * v5) = 2;
  *(_QWORD *)(v3 + 8 * v5 + 16) = "hkaPose";
  *(_QWORD *)(v3 + 8 * v5 + 48) = 0i64;
  v6 = *(_BYTE *)(v3 + 81);
  if ( v4 > v6 )
    v6 = v4;
  *(_BYTE *)(v3 + 81) = v6;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 80i64);
  v9 = (_DWORD *)v8;
  v36 = v8;
  if ( v8 )
  {
    *(_QWORD *)v8 = v2[3].mNode.mParent->mChild[0];
    *(_QWORD *)(v8 + 8) = 0i64;
    *(_DWORD *)(v8 + 16) = 0;
    *(_DWORD *)(v8 + 20) = 2147483648;
    *(_QWORD *)(v8 + 24) = 0i64;
    *(_DWORD *)(v8 + 32) = 0;
    *(_DWORD *)(v8 + 36) = 2147483648;
    *(_QWORD *)(v8 + 40) = 0i64;
    *(_DWORD *)(v8 + 48) = 0;
    *(_DWORD *)(v8 + 52) = 2147483648;
    *(_WORD *)(v8 + 56) = 0;
    *(_QWORD *)(v8 + 64) = 0i64;
    *(_DWORD *)(v8 + 72) = 0;
    *(_DWORD *)(v8 + 76) = 2147483648;
    v10 = *(_DWORD *)(*(_QWORD *)v8 + 48i64);
    v11 = (v10 + 3) & 0xFFFFFFFC;
    if ( (*(_DWORD *)(v8 + 36) & 0x3FFFFFFF) >= v11 )
      result.m_enum = 0;
    else
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (void *)(v8 + 24),
        v11,
        48);
    if ( (v9[5] & 0x3FFFFFFF) >= v11 )
      v39.m_enum = 0;
    else
      hkArrayUtil::_reserve(&v39, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9 + 2, v11, 48);
    if ( (v9[13] & 0x3FFFFFFF) >= v11 )
      v40.m_enum = 0;
    else
      hkArrayUtil::_reserve(&v40, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9 + 10, v11, 4);
    v12 = v9[9] & 0x3FFFFFFF;
    if ( v12 >= v10 )
    {
      v30.m_enum = 0;
    }
    else
    {
      v13 = 2 * v12;
      v14 = v10;
      if ( v10 < v13 )
        v14 = v13;
      hkArrayUtil::_reserve(&v30, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9 + 6, v14, 48);
    }
    v9[8] = v10;
    v15 = v9[5] & 0x3FFFFFFF;
    if ( v15 >= v10 )
    {
      v31.m_enum = 0;
    }
    else
    {
      v16 = 2 * v15;
      v17 = v10;
      if ( v10 < v16 )
        v17 = v16;
      hkArrayUtil::_reserve(&v31, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9 + 2, v17, 48);
    }
    v9[4] = v10;
    v18 = v9[13] & 0x3FFFFFFF;
    if ( v18 >= v10 )
    {
      v32.m_enum = 0;
    }
    else
    {
      v19 = 2 * v18;
      v20 = v10;
      if ( v10 < v19 )
        v20 = v19;
      hkArrayUtil::_reserve(&v32, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9 + 10, v20, 4);
    }
    v9[12] = v10;
    v21 = *(_DWORD *)(*(_QWORD *)v9 + 96i64);
    v22 = (v21 + 3) & 0xFFFFFFFC;
    if ( (v9[19] & 0x3FFFFFFF) >= v22 )
      v33.m_enum = 0;
    else
      hkArrayUtil::_reserve(&v33, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9 + 16, v22, 4);
    v23 = v9[19] & 0x3FFFFFFF;
    if ( v23 >= v21 )
    {
      v34.m_enum = 0;
    }
    else
    {
      v24 = 2 * v23;
      v25 = v21;
      if ( v21 < v24 )
        v25 = v24;
      hkArrayUtil::_reserve(&v34, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9 + 16, v25, 4);
    }
    v26 = v21 - v9[18];
    v27 = (_DWORD *)(*((_QWORD *)v9 + 8) + 4i64 * (signed int)v9[18]);
    v28 = v26;
    if ( v26 > 0 )
    {
      while ( v28 )
      {
        *v27 = 0;
        ++v27;
        --v28;
      }
    }
    v9[18] = v21;
  }
  else
  {
    v9 = 0i64;
  }
  v38[31] = v9;
  v29 = *(_BYTE *)(v3 + 80);
  if ( v29 > 0 )
  {
    *(_BYTE *)(v3 + 80) = v29 - 1;
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
  _QWORD *v3; // rbx
  _QWORD **v4; // rax

  v2 = *((_QWORD *)userData + 31);
  v3 = userData;
  if ( v2 )
  {
    hkaPose::~hkaPose(*((hkaPose **)userData + 31));
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v4[11] + 16i64))(v4[11], v2, 80i64);
    v3[31] = 0i64;
  }
  else
  {
    *((_QWORD *)userData + 31) = 0i64;
  }
}

// File Line: 955
// RVA: 0x1BB210
void __fastcall DrawBoneHavok(hkaSkeleton *skeleton, hkQsTransformf *poseModelSpace, hkQsTransformf *worldFromModel, const bool *boneDraw, UFG::qColour *colour)
{
  const bool *v5; // r14
  hkQsTransformf *v6; // r13
  hkaSkeleton *v7; // rsi
  Render::DebugDrawContext *v8; // rax
  int v9; // edi
  __m128 v10; // xmm1
  signed __int16 v11; // bx
  __int64 v12; // rdi
  const bool *v13; // r15
  __int64 v14; // r12
  hkQsTransformf *v15; // r14
  __int16 v16; // cx
  __m128 v17; // xmm8
  __m128 v18; // xmm6
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
  UFG::qVector3 world_position; // [rsp+30h] [rbp-D0h]
  UFG::qStringBuilder v36; // [rsp+40h] [rbp-C0h]
  Render::DebugDrawContext *v37; // [rsp+50h] [rbp-B0h]
  hkVector4f v38; // [rsp+60h] [rbp-A0h]
  UFG::qVector3 line_points; // [rsp+70h] [rbp-90h]
  unsigned __int64 v40; // [rsp+7Ch] [rbp-84h]
  int v41; // [rsp+84h] [rbp-7Ch]
  hkVector4f v42; // [rsp+90h] [rbp-70h]
  UFG::qStringBuilder v43; // [rsp+A0h] [rbp-60h]
  UFG::qStringBuilder v44; // [rsp+B0h] [rbp-50h]
  UFG::qStringBuilder v45; // [rsp+C0h] [rbp-40h]
  __int64 v46; // [rsp+D0h] [rbp-30h]
  hkQsTransformf v47; // [rsp+E0h] [rbp-20h]
  float d; // [rsp+110h] [rbp+10h]
  UFG::qVector3 v49; // [rsp+140h] [rbp+40h]
  int v50; // [rsp+1C0h] [rbp+C0h]
  hkQsTransformf *b; // [rsp+1C8h] [rbp+C8h]
  const bool *v52; // [rsp+1D8h] [rbp+D8h]

  v52 = boneDraw;
  b = poseModelSpace;
  v46 = -2i64;
  v5 = boneDraw;
  v6 = worldFromModel;
  v7 = skeleton;
  v8 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v37 = v8;
  v9 = v7->m_bones.m_size;
  v50 = v7->m_bones.m_size;
  if ( gDrawSkeletonName )
  {
    v10 = v6->m_translation.m_quad;
    LODWORD(world_position.x) = v6->m_translation;
    LODWORD(world_position.y) = (unsigned __int128)_mm_shuffle_ps(v10, v10, 85);
    world_position.z = v6->m_translation.m_quad.m128_f32[2];
    Render::DebugDrawContext::DrawText(
      v8,
      &world_position,
      colour,
      (const char *)((_QWORD)v7->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
  }
  v11 = 0;
  if ( (signed __int16)v9 > 0 )
  {
    v12 = 0i64;
    v13 = v5;
    v14 = 0i64;
    v15 = b;
    do
    {
      hkVector4f::setTransformedPos(&v42, v6, &v15->m_translation);
      v16 = v7->m_parentIndices.m_data[v14];
      if ( v16 == -1 )
      {
        v38.m_quad = 0i64;
      }
      else
      {
        hkVector4f::setTransformedPos(&v38, v6, &b[v16].m_translation);
        *(_QWORD *)&line_points.x = v42.m_quad.m128_u64[0];
        line_points.z = v42.m_quad.m128_f32[2];
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
      if ( sShowCoords && v52 )
      {
        if ( gDrawSkeletonBoneNameFilter.mLength )
        {
          if ( (unsigned int)UFG::qWildcardMatchInsensitive(
                               gDrawSkeletonBoneNameFilter.mData,
                               (const char *)((_QWORD)v7->m_bones.m_data[v12].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
            goto LABEL_15;
        }
        else if ( gDrawSkeletonBoneIDFilter < 0 || gDrawSkeletonBoneIDFilter == v11 )
        {
LABEL_15:
          if ( *v13 || gDrawSkeletonAllCoords || gDrawSkeletonBoneNames || gDrawSkeletonBoneTranslationLockInfo )
          {
            v17 = v15->m_rotation.m_vec.m_quad;
            v18 = v6->m_rotation.m_vec.m_quad;
            v19 = _mm_shuffle_ps(v18, v18, 255);
            v20 = _mm_mul_ps(v15->m_translation.m_quad, v18);
            v21 = _mm_mul_ps(
                    v6->m_rotation.m_vec.m_quad,
                    _mm_add_ps(
                      _mm_shuffle_ps(v20, v20, 170),
                      _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0))));
            v22 = _mm_sub_ps(
                    _mm_mul_ps(
                      v6->m_rotation.m_vec.m_quad,
                      _mm_shuffle_ps(v15->m_translation.m_quad, v15->m_translation.m_quad, 201)),
                    _mm_mul_ps(v15->m_translation.m_quad, _mm_shuffle_ps(v6->m_rotation.m_vec.m_quad, v18, 201)));
            v23 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(v15->m_translation.m_quad, _mm_sub_ps(_mm_mul_ps(v19, v19), (__m128)xmmword_141A711B0)),
                      v21),
                    _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v19));
            v47.m_translation.m_quad = _mm_add_ps(_mm_add_ps(v23, v23), v6->m_translation.m_quad);
            v24 = _mm_shuffle_ps(v17, v17, 255);
            v25 = _mm_sub_ps(
                    _mm_mul_ps(v18, _mm_shuffle_ps(v17, v17, 201)),
                    _mm_mul_ps(v17, _mm_shuffle_ps(v18, v18, 201)));
            v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 201), _mm_mul_ps(v17, v19)), _mm_mul_ps(v18, v24));
            v27 = _mm_mul_ps(v17, v18);
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
            v47.m_scale.m_quad = _mm_mul_ps(v6->m_scale.m_quad, v15->m_scale.m_quad);
            v29 = _mm_mul_ps(v28, v28);
            v30 = _mm_add_ps(v29, _mm_shuffle_ps(v29, v29, 78));
            v31 = _mm_add_ps(_mm_shuffle_ps(v30, v30, 177), v30);
            v32 = _mm_rsqrt_ps(v31);
            v47.m_rotation.m_vec.m_quad = _mm_mul_ps(
                                            v28,
                                            _mm_mul_ps(
                                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
                                              _mm_mul_ps(v32, *(__m128 *)_xmm)));
            hkQsTransformf::get4x4ColumnMajor(&v47, &d);
            world_position = v49;
            if ( *v13 || gDrawSkeletonAllCoords )
            {
              v33 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                  Render::DebugDrawManager::mInstance,
                                                  1u);
              Render::DebugDrawContext::DrawCoord(v33, (UFG::qMatrix44 *)&d, gDrawSkeletonAllCoordsScale, 0i64);
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
                  (_QWORD)v7->m_bones.m_data[v12].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
                  (unsigned int)v11);
                UFG::qStringBuilder::Add(&v36, v45.mBuffer, -1);
                UFG::qStringBuilder::~qStringBuilder(&v45);
              }
              if ( gDrawSkeletonBoneTranslationLockInfo )
              {
                UFG::qStringBuilder::qStringBuilder(&v44);
                v34 = "U";
                if ( v7->m_bones.m_data[v12].m_lockTranslation.m_bool )
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
          goto LABEL_35;
        }
      }
LABEL_35:
      ++v11;
      ++v14;
      ++v15;
      ++v13;
      ++v12;
    }
    while ( v11 < (signed __int16)v50 );
  }
}

