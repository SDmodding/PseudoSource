// File Line: 45
// RVA: 0x16A460
UFG::qReflectResource::Construct

// File Line: 158
// RVA: 0x16C600
void __fastcall UFG::qReflectResource::Destroy(UFG::qReflectResource *this)
{
  UFG::qReflectResource *v1; // r14
  unsigned int v2; // edi
  __int64 v3; // rax
  signed __int64 v4; // rcx
  _QWORD *v5; // rdx
  char *v6; // rbx
  unsigned __int64 v7; // rbx
  UFG::qReflectWarehouse *v8; // rax
  unsigned int i; // ebp
  __int64 v10; // rax
  signed __int64 v11; // rcx
  unsigned __int64 v12; // rsi
  UFG::qReflectObject *v13; // rdi
  unsigned __int64 v14; // rbx
  UFG::qReflectWarehouse *v15; // rax
  signed __int64 v16; // rbx
  unsigned int j; // edi
  __int64 v18; // rax
  signed __int64 v19; // rcx
  unsigned __int64 *v20; // rbx
  unsigned __int64 v21; // rdx
  __int64 v22; // rax
  unsigned __int64 v23; // rcx
  signed __int64 v24; // rcx
  unsigned int k; // edx
  __int64 v26; // rax
  signed __int64 v27; // r8
  _QWORD *v28; // rax
  _QWORD *v29; // rax
  unsigned int l; // ecx
  __int64 v31; // rax
  signed __int64 v32; // rdx
  _QWORD *v33; // r8
  _QWORD *v34; // rax

  v1 = this;
  v2 = 0;
  if ( this->mObjectCount )
  {
    do
    {
      v3 = v1->mObjectTable.mOffset;
      if ( v3 )
        v4 = (signed __int64)&v1->mObjectTable + v3;
      else
        v4 = 0i64;
      v5 = (_QWORD *)(v4 + ((unsigned __int64)v2 << 7));
      v6 = (char *)v5 + *v5;
      if ( !*v5 )
        v6 = 0i64;
      v7 = *((_QWORD *)v6 + 7);
      if ( !(_S12 & 1) )
      {
        _S12 |= 1u;
        sReflectWarehouse.mInventoryTree.mTree.mHead.mUID = 0i64;
        sReflectWarehouse.mInventoryTree.mTree.mHead.mParent = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
        sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[0] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
        sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[1] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
        sReflectWarehouse.mInventoryTree.mTree.mHead.mNeighbours[0] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
        sReflectWarehouse.mInventoryTree.mTree.mHead.mNeighbours[1] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
        sReflectWarehouse.mInventoryTree.mTree.mCount = 0i64;
        atexit(UFG::qReflectWarehouse::Instance_::_2_::_dynamic_atexit_destructor_for__sReflectWarehouse__);
      }
      v8 = (UFG::qReflectWarehouse *)sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[0];
      while ( v8 != &sReflectWarehouse )
      {
        if ( v8->mInventoryTree.mTree.mHead.mUID >= v7 )
        {
          if ( v8->mInventoryTree.mTree.mHead.mUID <= v7 )
            break;
          v8 = (UFG::qReflectWarehouse *)v8->mInventoryTree.mTree.mHead.mChildren[0];
        }
        else
        {
          v8 = (UFG::qReflectWarehouse *)v8->mInventoryTree.mTree.mHead.mChildren[1];
        }
      }
      ++v2;
    }
    while ( v2 < v1->mObjectCount );
  }
  for ( i = 0; i < v1->mObjectCount; ++i )
  {
    v10 = v1->mObjectTable.mOffset;
    if ( v10 )
      v11 = (signed __int64)&v1->mObjectTable + v10;
    else
      v11 = 0i64;
    v12 = v11 + ((unsigned __int64)i << 7);
    v13 = (UFG::qReflectObject *)(*(_QWORD *)v12 + v12);
    if ( !*(_QWORD *)v12 )
      v13 = 0i64;
    v14 = v13->mTypeUID;
    if ( !(_S12 & 1) )
    {
      _S12 |= 1u;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mUID = 0i64;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mParent = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[0] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[1] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mNeighbours[0] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mNeighbours[1] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mCount = 0i64;
      atexit(UFG::qReflectWarehouse::Instance_::_2_::_dynamic_atexit_destructor_for__sReflectWarehouse__);
    }
    v15 = (UFG::qReflectWarehouse *)sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[0];
    while ( v15 != &sReflectWarehouse )
    {
      if ( v15->mInventoryTree.mTree.mHead.mUID >= v14 )
      {
        if ( v15->mInventoryTree.mTree.mHead.mUID <= v14 )
        {
          v16 = (signed __int64)&v15[-1].mInventoryTree.mTree.mCount;
          if ( v15 != (UFG::qReflectWarehouse *)8 )
          {
            UFG::qReflectInventoryBase::Remove((UFG::qReflectInventoryBase *)&v15[-1].mInventoryTree.mTree.mCount, v13);
            if ( *(_QWORD *)(v12 + 72) != -1i64 )
            {
              if ( v12 != -16i64 )
                UFG::qTree64Base::Remove((UFG::qTree64Base *)(v16 + 120), (UFG::qTree64Base::BaseNode *)(v12 + 16));
              if ( v12 != -72i64 )
                UFG::qTree64Base::Remove((UFG::qTree64Base *)(v16 + 176), (UFG::qTree64Base::BaseNode *)(v12 + 72));
            }
          }
          break;
        }
        v15 = (UFG::qReflectWarehouse *)v15->mInventoryTree.mTree.mHead.mChildren[0];
      }
      else
      {
        v15 = (UFG::qReflectWarehouse *)v15->mInventoryTree.mTree.mHead.mChildren[1];
      }
    }
  }
  for ( j = 0; j < v1->mSerializeCount; ++j )
  {
    v18 = v1->mSerializeTable.mOffset;
    if ( v18 )
      v19 = (signed __int64)&v1->mSerializeTable + v18;
    else
      v19 = 0i64;
    v20 = (unsigned __int64 *)(v19 + 16i64 * j);
    if ( !(_S10_0 & 1) )
    {
      _S10_0 |= 1u;
      sOpsInstance.mOpTree.mTree.mHead.mUID = 0i64;
      unk_14235BC68 = &sOpsInstance;
      unk_14235BC70 = &sOpsInstance;
      unk_14235BC78 = &sOpsInstance;
      unk_14235BC80 = &sOpsInstance;
      unk_14235BC88 = &sOpsInstance;
      unk_14235BC90 = 0i64;
      stru_14235BC98.mNode.mPrev = (UFG::qNode<UFG::EditNotification,UFG::EditNotification> *)&stru_14235BC98;
      stru_14235BC98.mNode.mNext = (UFG::qNode<UFG::EditNotification,UFG::EditNotification> *)&stru_14235BC98;
      atexit(UFG::qOpRegistry::Instance_::_2_::_dynamic_atexit_destructor_for__sOpsInstance__);
    }
    v21 = *v20;
    v22 = unk_14235BC70;
    while ( (UFG::qOpRegistry *)v22 != &sOpsInstance )
    {
      if ( *(_QWORD *)v22 >= v21 )
      {
        if ( *(_QWORD *)v22 <= v21 )
        {
          if ( v22 )
          {
            v23 = v20[1];
            if ( v23 )
              v24 = (signed __int64)v20 + v23 + 8;
            else
              v24 = 0i64;
            (*(void (__fastcall **)(signed __int64))(v22 + 56))(v24);
          }
          break;
        }
        v22 = *(_QWORD *)(v22 + 16);
      }
      else
      {
        v22 = *(_QWORD *)(v22 + 24);
      }
    }
  }
  for ( k = 0; k < v1->mArrayCount; ++k )
  {
    v26 = v1->mArrayTable.mOffset;
    if ( v26 )
      v27 = (signed __int64)&v1->mArrayTable + v26;
    else
      v27 = 0i64;
    v28 = (_QWORD *)(v27 + 24i64 * k);
    if ( *v28 )
      v29 = (_QWORD *)((char *)v28 + *v28);
    else
      v29 = 0i64;
    v29[1] = 0i64;
    *v29 = 0i64;
  }
  for ( l = 0; l < v1->mPatchCount; ++l )
  {
    v31 = v1->mPatchTable.mOffset;
    if ( v31 )
      v32 = (signed __int64)&v1->mPatchTable + v31;
    else
      v32 = 0i64;
    v33 = (_QWORD *)(v32 + 16i64 * l);
    if ( *v33 )
      v34 = (_QWORD *)((char *)v33 + *v33);
    else
      v34 = 0i64;
    *v34 = 0i64;
  }
}

// File Line: 238
// RVA: 0x14681E0
__int64 UFG::_dynamic_initializer_for__gqReflectResourceInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gqReflectResourceInventory.vfptr,
    "qReflectResourceInventory",
    0x5B00F999u,
    0x616A903Fu,
    0,
    0);
  UFG::gqReflectResourceInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::qReflectResourceInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gqReflectResourceInventory__);
}

// File Line: 246
// RVA: 0x1656B0
void __fastcall UFG::qReflectResourceInventory::Add(UFG::qReflectResourceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qReflectResourceInventory *v3; // rdi
  UFG::qReflectResource *v4; // rcx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v5; // [rsp+58h] [rbp+20h]

  v2 = resource_data;
  v3 = this;
  v4 = 0i64;
  if ( resource_data )
  {
    resource_data->mNode.mParent = 0i64;
    resource_data->mNode.mChild[0] = 0i64;
    resource_data->mNode.mChild[1] = 0i64;
    v5 = &resource_data->mResourceHandles;
    v5->mNode.mPrev = &v5->mNode;
    v5->mNode.mNext = &v5->mNode;
    v4 = (UFG::qReflectResource *)resource_data;
  }
  UFG::qReflectResource::Construct(v4);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 255
// RVA: 0x17A310
void __fastcall UFG::qReflectResourceInventory::Remove(UFG::qReflectResourceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qReflectResource *v2; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v5; // [rsp+48h] [rbp+10h]

  v2 = (UFG::qReflectResource *)resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  UFG::qReflectResource::Destroy(v2);
  v5 = &v2->mResourceHandles;
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v2->mResourceHandles);
  v3 = v2->mResourceHandles.mNode.mPrev;
  v4 = v2->mResourceHandles.mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
}

