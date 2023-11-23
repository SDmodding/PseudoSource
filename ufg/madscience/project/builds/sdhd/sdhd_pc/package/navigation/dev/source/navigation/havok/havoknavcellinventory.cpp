// File Line: 19
// RVA: 0x1460CA0
__int64 UFG::_dynamic_initializer_for__gNavCellInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gNavCellInventory,
    "NavMeshDataInventory",
    0x5D7E8ADFu,
    0xDD3C7B19,
    0,
    0);
  UFG::gNavCellInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::NavCellInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gNavCellInventory__);
}

// File Line: 41
// RVA: 0xE7BD0
void __fastcall UFG::NavCellInventory::Add(UFG::NavCellInventory *this, UFG::qResourceData *resource_data)
{
  __int64 v4; // rdi
  char v5; // r8
  char v6; // cl
  unsigned int navmeshSize; // ecx
  __int64 v8; // rax
  const char *userEdgesData; // r11
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax
  const char *mediatorTreeData; // rdx
  UFG::qBaseNodeRB *v12; // rax
  const char *v13; // r9
  char v14; // al

  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v5 = ++*(_BYTE *)(v4 + 80);
  *(_DWORD *)(v4 + 4i64 * v5) = 1;
  *(_QWORD *)(v4 + 8i64 * v5 + 16) = "AI::NavCellInventory::Add";
  *(_QWORD *)(v4 + 8i64 * v5 + 48) = 0i64;
  v6 = *(_BYTE *)(v4 + 81);
  if ( v5 > v6 )
    v6 = v5;
  *(_BYTE *)(v4 + 81) = v6;
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  if ( LODWORD(resource_data[1].mNode.mParent) == 4 )
  {
    navmeshSize = (unsigned int)resource_data[1].mNode.mChild[0];
    if ( navmeshSize )
    {
      if ( UFG::NavManager::ms_pInstance )
      {
        v8 = *(_QWORD *)&resource_data[1].mTypeUID;
        if ( v8 )
          userEdgesData = (char *)&resource_data[1].mTypeUID + v8;
        else
          userEdgesData = 0i64;
        mPrev = resource_data[1].mResourceHandles.mNode.mPrev;
        if ( mPrev )
          mediatorTreeData = (char *)&resource_data[1].mResourceHandles + (_QWORD)mPrev;
        else
          mediatorTreeData = 0i64;
        v12 = resource_data[1].mNode.mChild[1];
        if ( v12 )
          v13 = (char *)&resource_data[1].mNode.mChild[1] + (_QWORD)v12;
        else
          v13 = 0i64;
        UFG::HavokNavManager::LoadNavMesh(
          (UFG::HavokNavManager *)UFG::NavManager::ms_pInstance,
          HIDWORD(resource_data[1].mNode.mParent),
          resource_data->mDebugName,
          v13,
          navmeshSize,
          mediatorTreeData,
          resource_data[1].mNode.mUID,
          userEdgesData,
          (unsigned int)resource_data[1].mResourceHandles.mNode.mNext);
        UFG::InterestPoint::AISectionLoadedCallback();
      }
    }
  }
  v14 = *(_BYTE *)(v4 + 80);
  if ( v14 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v14 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 79
// RVA: 0xF07A0
void __fastcall UFG::NavCellInventory::Remove(UFG::NavCellInventory *this, UFG::qResourceData *resource_data)
{
  if ( LODWORD(resource_data[1].mNode.mParent) == 4
    && LODWORD(resource_data[1].mNode.mChild[0])
    && UFG::NavManager::ms_pInstance )
  {
    UFG::HavokNavManager::UnloadNavMesh(
      (UFG::HavokNavManager *)UFG::NavManager::ms_pInstance,
      HIDWORD(resource_data[1].mNode.mParent));
  }
  UFG::qResourceInventory::Remove(this, resource_data);
}

