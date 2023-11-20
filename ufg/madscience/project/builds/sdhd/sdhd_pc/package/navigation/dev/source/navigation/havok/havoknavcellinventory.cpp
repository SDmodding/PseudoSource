// File Line: 19
// RVA: 0x1460CA0
__int64 UFG::_dynamic_initializer_for__gNavCellInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gNavCellInventory.vfptr,
    "NavMeshDataInventory",
    0x5D7E8ADFu,
    0xDD3C7B19,
    0,
    0);
  UFG::gNavCellInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::NavCellInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gNavCellInventory__);
}

// File Line: 41
// RVA: 0xE7BD0
void __fastcall UFG::NavCellInventory::Add(UFG::NavCellInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::NavCellInventory *v3; // rsi
  signed __int64 v4; // rdi
  char v5; // r8
  __int64 v6; // rax
  char v7; // cl
  unsigned int navmeshSize; // ecx
  __int64 v9; // rax
  const char *userEdgesData; // r11
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v11; // rax
  const char *mediatorTreeData; // rdx
  UFG::qBaseNodeRB *v13; // rax
  const char *v14; // r9
  char v15; // al

  v2 = resource_data;
  v3 = this;
  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v5 = ++*(_BYTE *)(v4 + 80);
  v6 = v5;
  *(_DWORD *)(v4 + 4 * v6) = 1;
  *(_QWORD *)(v4 + 8 * v6 + 16) = "AI::NavCellInventory::Add";
  *(_QWORD *)(v4 + 8 * v6 + 48) = 0i64;
  v7 = *(_BYTE *)(v4 + 81);
  if ( v5 > v7 )
    v7 = v5;
  *(_BYTE *)(v4 + 81) = v7;
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  if ( LODWORD(v2[1].mNode.mParent) == 4 )
  {
    navmeshSize = (unsigned int)v2[1].mNode.mChild[0];
    if ( navmeshSize )
    {
      if ( UFG::NavManager::ms_pInstance )
      {
        v9 = *(_QWORD *)&v2[1].mTypeUID;
        if ( v9 )
          userEdgesData = (char *)&v2[1].mTypeUID + v9;
        else
          userEdgesData = 0i64;
        v11 = v2[1].mResourceHandles.mNode.mPrev;
        if ( v11 )
          mediatorTreeData = (char *)&v2[1].mResourceHandles + (_QWORD)v11;
        else
          mediatorTreeData = 0i64;
        v13 = v2[1].mNode.mChild[1];
        if ( v13 )
          v14 = (char *)&v2[1].mNode.mChild[1] + (_QWORD)v13;
        else
          v14 = 0i64;
        UFG::HavokNavManager::LoadNavMesh(
          (UFG::HavokNavManager *)UFG::NavManager::ms_pInstance,
          HIDWORD(v2[1].mNode.mParent),
          v2->mDebugName,
          v14,
          navmeshSize,
          mediatorTreeData,
          v2[1].mNode.mUID,
          userEdgesData,
          (unsigned int)v2[1].mResourceHandles.mNode.mNext);
        UFG::InterestPoint::AISectionLoadedCallback();
      }
    }
  }
  v15 = *(_BYTE *)(v4 + 80);
  if ( v15 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v15 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 79
// RVA: 0xF07A0
void __fastcall UFG::NavCellInventory::Remove(UFG::NavCellInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::NavCellInventory *v3; // rdi

  v2 = resource_data;
  v3 = this;
  if ( LODWORD(resource_data[1].mNode.mParent) == 4
    && LODWORD(resource_data[1].mNode.mChild[0])
    && UFG::NavManager::ms_pInstance )
  {
    UFG::HavokNavManager::UnloadNavMesh(
      (UFG::HavokNavManager *)UFG::NavManager::ms_pInstance,
      HIDWORD(resource_data[1].mNode.mParent));
  }
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&v3->vfptr, v2);
}

