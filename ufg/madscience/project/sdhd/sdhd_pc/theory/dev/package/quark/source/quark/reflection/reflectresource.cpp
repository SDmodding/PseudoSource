// File Line: 45
// RVA: 0x16A460
void __fastcall UFG::qReflectResource::Construct(UFG::qReflectResource *this)
{
  char *v2; // r9
  unsigned int i; // edx
  __int64 mOffset; // rax
  char *v5; // rcx
  char *v6; // rax
  char *v7; // rcx
  __int64 v8; // r8
  char *v9; // rax
  unsigned __int64 j; // r8
  __int64 v11; // rax
  char *v12; // rdx
  char *v13; // rdx
  char *v14; // rcx
  __int64 v15; // rax
  char *v16; // rax
  unsigned int v17; // edi
  unsigned int k; // esi
  __int64 v19; // rax
  char *v20; // rcx
  char *v21; // rdx
  char *v22; // rbx
  unsigned __int64 v23; // rbx
  UFG::qReflectWarehouse *v24; // rax
  unsigned int m; // r15d
  __int64 v26; // rax
  char *v27; // rcx
  char *v28; // rdi
  char *v29; // r14
  unsigned __int64 v30; // rbx
  UFG::qReflectWarehouse *v31; // rax
  __int64 *p_mCount; // rbp
  UFG::qTree64Base::BaseNode *v33; // rdx
  unsigned __int64 *v34; // rbx
  __int64 v35; // rax
  char n; // al
  unsigned int v37; // edi
  __int64 v38; // rax
  char *v39; // rcx
  char *v40; // rbx
  unsigned __int64 v41; // rdx
  __int64 v42; // rax
  __int64 v43; // rcx
  char *v44; // rcx
  unsigned int ii; // edi
  __int64 v46; // rax
  char *v47; // rcx
  char *v48; // rdx
  UFG::qReflectObject *v49; // rbp
  unsigned __int64 mTypeUID; // rbx
  UFG::qReflectWarehouse *v51; // rax

  v2 = 0i64;
  for ( i = 0; i < this->mPatchCount; ++i )
  {
    mOffset = this->mPatchTable.mOffset;
    if ( mOffset )
      v5 = (char *)&this->mPatchTable + mOffset;
    else
      v5 = 0i64;
    v6 = &v5[16 * i];
    if ( *(_QWORD *)v6 )
      v7 = &v6[*(_QWORD *)v6];
    else
      v7 = 0i64;
    v8 = *((_QWORD *)v6 + 1);
    if ( v8 )
      v9 = &v6[v8 + 8];
    else
      v9 = 0i64;
    *(_QWORD *)v7 = v9;
  }
  for ( j = 0i64; (unsigned int)j < this->mArrayCount; j = (unsigned int)(j + 1) )
  {
    v11 = this->mArrayTable.mOffset;
    if ( v11 )
      v12 = (char *)&this->mArrayTable + v11;
    else
      v12 = 0i64;
    v13 = &v12[24 * (unsigned int)j];
    v14 = &v13[*(_QWORD *)v13];
    if ( !*(_QWORD *)v13 )
      v14 = 0i64;
    *((_DWORD *)v14 + 3) |= 2u;
    *((_DWORD *)v14 + 2) = *((_DWORD *)v13 + 4);
    v15 = *((_QWORD *)v13 + 1);
    if ( v15 )
      v16 = &v13[v15 + 8];
    else
      v16 = 0i64;
    *(_QWORD *)v14 = v16;
  }
  v17 = 0;
  for ( k = _S12; v17 < this->mObjectCount; ++v17 )
  {
    v19 = this->mObjectTable.mOffset;
    if ( v19 )
      v20 = (char *)&this->mObjectTable + v19;
    else
      v20 = 0i64;
    v21 = &v20[128 * (unsigned __int64)v17];
    v22 = &v21[*(_QWORD *)v21];
    if ( !*(_QWORD *)v21 )
      v22 = 0i64;
    v23 = *((_QWORD *)v22 + 7);
    if ( (k & 1) == 0 )
    {
      _S12 = k | 1;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mUID = 0i64;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mParent = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[0] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[1] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mNeighbours[0] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mNeighbours[1] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mCount = 0i64;
      atexit(UFG::qReflectWarehouse::Instance_::_2_::_dynamic_atexit_destructor_for__sReflectWarehouse__);
      k = _S12;
      v2 = 0i64;
    }
    v24 = (UFG::qReflectWarehouse *)sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[0];
    while ( v24 != &sReflectWarehouse )
    {
      if ( v24->mInventoryTree.mTree.mHead.mUID >= v23 )
      {
        if ( v24->mInventoryTree.mTree.mHead.mUID <= v23 )
          break;
        v24 = (UFG::qReflectWarehouse *)v24->mInventoryTree.mTree.mHead.mChildren[0];
      }
      else
      {
        v24 = (UFG::qReflectWarehouse *)v24->mInventoryTree.mTree.mHead.mChildren[1];
      }
    }
  }
  for ( m = 0; m < this->mObjectCount; v2 = 0i64 )
  {
    v26 = this->mObjectTable.mOffset;
    if ( v26 )
      v27 = (char *)&this->mObjectTable + v26;
    else
      v27 = 0i64;
    v28 = &v27[128 * (unsigned __int64)m];
    v29 = &v28[*(_QWORD *)v28];
    if ( !*(_QWORD *)v28 )
      v29 = 0i64;
    v30 = *((_QWORD *)v29 + 7);
    if ( (k & 1) == 0 )
    {
      _S12 = k | 1;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mUID = 0i64;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mParent = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[0] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[1] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mNeighbours[0] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mNeighbours[1] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mCount = 0i64;
      atexit(UFG::qReflectWarehouse::Instance_::_2_::_dynamic_atexit_destructor_for__sReflectWarehouse__);
      k = _S12;
      v2 = 0i64;
    }
    v31 = (UFG::qReflectWarehouse *)sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[0];
    while ( v31 != &sReflectWarehouse )
    {
      if ( v31->mInventoryTree.mTree.mHead.mUID >= v30 )
      {
        if ( v31->mInventoryTree.mTree.mHead.mUID <= v30 )
        {
          p_mCount = &v31[-1].mInventoryTree.mTree.mCount;
          goto LABEL_54;
        }
        v31 = (UFG::qReflectWarehouse *)v31->mInventoryTree.mTree.mHead.mChildren[0];
      }
      else
      {
        v31 = (UFG::qReflectWarehouse *)v31->mInventoryTree.mTree.mHead.mChildren[1];
      }
    }
    p_mCount = 0i64;
LABEL_54:
    v33 = (UFG::qTree64Base::BaseNode *)(v28 + 16);
    if ( v28 != (char *)-16i64 )
    {
      v33->mUID = 0i64;
      *((_QWORD *)v28 + 3) = v28 + 16;
      *((_QWORD *)v28 + 4) = v28 + 16;
      *((_QWORD *)v28 + 5) = v28 + 16;
      *((_QWORD *)v28 + 6) = v28 + 16;
      *((_QWORD *)v28 + 7) = v28 + 16;
    }
    v34 = (unsigned __int64 *)(v28 + 72);
    if ( v28 != (char *)-72i64 )
    {
      *v34 = 0i64;
      *((_QWORD *)v28 + 10) = v28 + 72;
      *((_QWORD *)v28 + 11) = v28 + 72;
      *((_QWORD *)v28 + 12) = v28 + 72;
      *((_QWORD *)v28 + 13) = v28 + 72;
      *((_QWORD *)v28 + 14) = v28 + 72;
    }
    v35 = *((_QWORD *)v28 + 1);
    if ( v35 )
      v2 = &v28[v35 + 8];
    *((_QWORD *)v28 + 8) = v2;
    v33->mUID = *((_QWORD *)v29 + 1);
    j = -1i64;
    if ( v2 )
    {
      for ( n = *v2; *v2; n = *v2 )
      {
        j = (j >> 8) ^ sCrcTable64[(unsigned __int8)(j ^ n)];
        ++v2;
      }
    }
    *v34 = j;
    if ( j != -1i64 && p_mCount )
    {
      UFG::qTree64Base::Add((UFG::qTree64Base *)(p_mCount + 15), v33);
      UFG::qTree64Base::Add((UFG::qTree64Base *)(p_mCount + 22), (UFG::qTree64Base::BaseNode *)(v28 + 72));
    }
    ++m;
  }
  v37 = 0;
  if ( this->mSerializeCount )
  {
    do
    {
      v38 = this->mSerializeTable.mOffset;
      if ( v38 )
        v39 = (char *)&this->mSerializeTable + v38;
      else
        v39 = 0i64;
      v40 = &v39[16 * v37];
      if ( (_S10_0 & 1) == 0 )
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
      v41 = *(_QWORD *)v40;
      v42 = unk_14235BC70;
      while ( (UFG::qOpRegistry *)v42 != &sOpsInstance )
      {
        if ( *(_QWORD *)v42 >= v41 )
        {
          if ( *(_QWORD *)v42 <= v41 )
          {
            if ( v42 )
            {
              v43 = *((_QWORD *)v40 + 1);
              if ( v43 )
                v44 = &v40[v43 + 8];
              else
                v44 = 0i64;
              (*(void (__fastcall **)(char *, unsigned __int64, unsigned __int64))(v42 + 48))(v44, v41, j);
            }
            break;
          }
          v42 = *(_QWORD *)(v42 + 16);
        }
        else
        {
          v42 = *(_QWORD *)(v42 + 24);
        }
      }
      ++v37;
    }
    while ( v37 < this->mSerializeCount );
    k = _S12;
  }
  for ( ii = 0; ii < this->mObjectCount; ++ii )
  {
    v46 = this->mObjectTable.mOffset;
    if ( v46 )
      v47 = (char *)&this->mObjectTable + v46;
    else
      v47 = 0i64;
    v48 = &v47[128 * (unsigned __int64)ii];
    v49 = (UFG::qReflectObject *)&v48[*(_QWORD *)v48];
    if ( !*(_QWORD *)v48 )
      v49 = 0i64;
    mTypeUID = v49->mTypeUID;
    if ( (k & 1) == 0 )
    {
      _S12 = k | 1;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mUID = 0i64;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mParent = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[0] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[1] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mNeighbours[0] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mHead.mNeighbours[1] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
      sReflectWarehouse.mInventoryTree.mTree.mCount = 0i64;
      atexit(UFG::qReflectWarehouse::Instance_::_2_::_dynamic_atexit_destructor_for__sReflectWarehouse__);
      k = _S12;
    }
    v51 = (UFG::qReflectWarehouse *)sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[0];
    while ( v51 != &sReflectWarehouse )
    {
      if ( v51->mInventoryTree.mTree.mHead.mUID >= mTypeUID )
      {
        if ( v51->mInventoryTree.mTree.mHead.mUID <= mTypeUID )
        {
          if ( v51 != (UFG::qReflectWarehouse *)8 )
          {
            UFG::qReflectInventoryBase::Add((UFG::qReflectInventoryBase *)&v51[-1].mInventoryTree.mTree.mCount, v49);
            k = _S12;
          }
          break;
        }
        v51 = (UFG::qReflectWarehouse *)v51->mInventoryTree.mTree.mHead.mChildren[0];
      }
      else
      {
        v51 = (UFG::qReflectWarehouse *)v51->mInventoryTree.mTree.mHead.mChildren[1];
      }
    }
  }
}

// File Line: 158
// RVA: 0x16C600
void __fastcall UFG::qReflectResource::Destroy(UFG::qReflectResource *this)
{
  unsigned int i; // edi
  __int64 mOffset; // rax
  char *v4; // rcx
  char *v5; // rdx
  char *v6; // rbx
  unsigned __int64 v7; // rbx
  UFG::qReflectWarehouse *v8; // rax
  unsigned int j; // ebp
  __int64 v10; // rax
  char *v11; // rcx
  char *v12; // rsi
  UFG::qReflectObject *v13; // rdi
  unsigned __int64 mTypeUID; // rbx
  UFG::qReflectWarehouse *v15; // rax
  __int64 *p_mCount; // rbx
  unsigned int k; // edi
  __int64 v18; // rax
  char *v19; // rcx
  char *v20; // rbx
  unsigned __int64 v21; // rdx
  __int64 v22; // rax
  __int64 v23; // rcx
  char *v24; // rcx
  unsigned int m; // edx
  __int64 v26; // rax
  char *v27; // r8
  char *v28; // rax
  char *v29; // rax
  unsigned int n; // ecx
  __int64 v31; // rax
  char *v32; // rdx
  char *v33; // r8
  char *v34; // rax

  for ( i = 0; i < this->mObjectCount; ++i )
  {
    mOffset = this->mObjectTable.mOffset;
    if ( mOffset )
      v4 = (char *)&this->mObjectTable + mOffset;
    else
      v4 = 0i64;
    v5 = &v4[128 * (unsigned __int64)i];
    v6 = &v5[*(_QWORD *)v5];
    if ( !*(_QWORD *)v5 )
      v6 = 0i64;
    v7 = *((_QWORD *)v6 + 7);
    if ( (_S12 & 1) == 0 )
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
  }
  for ( j = 0; j < this->mObjectCount; ++j )
  {
    v10 = this->mObjectTable.mOffset;
    if ( v10 )
      v11 = (char *)&this->mObjectTable + v10;
    else
      v11 = 0i64;
    v12 = &v11[128 * (unsigned __int64)j];
    v13 = (UFG::qReflectObject *)&v12[*(_QWORD *)v12];
    if ( !*(_QWORD *)v12 )
      v13 = 0i64;
    mTypeUID = v13->mTypeUID;
    if ( (_S12 & 1) == 0 )
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
      if ( v15->mInventoryTree.mTree.mHead.mUID >= mTypeUID )
      {
        if ( v15->mInventoryTree.mTree.mHead.mUID <= mTypeUID )
        {
          p_mCount = &v15[-1].mInventoryTree.mTree.mCount;
          if ( v15 != (UFG::qReflectWarehouse *)8 )
          {
            UFG::qReflectInventoryBase::Remove((UFG::qReflectInventoryBase *)&v15[-1].mInventoryTree.mTree.mCount, v13);
            if ( *((_QWORD *)v12 + 9) != -1i64 )
            {
              if ( v12 != (char *)-16i64 )
                UFG::qTree64Base::Remove((UFG::qTree64Base *)(p_mCount + 15), (UFG::qTree64Base::BaseNode *)(v12 + 16));
              if ( v12 != (char *)-72i64 )
                UFG::qTree64Base::Remove((UFG::qTree64Base *)(p_mCount + 22), (UFG::qTree64Base::BaseNode *)(v12 + 72));
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
  for ( k = 0; k < this->mSerializeCount; ++k )
  {
    v18 = this->mSerializeTable.mOffset;
    if ( v18 )
      v19 = (char *)&this->mSerializeTable + v18;
    else
      v19 = 0i64;
    v20 = &v19[16 * k];
    if ( (_S10_0 & 1) == 0 )
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
    v21 = *(_QWORD *)v20;
    v22 = unk_14235BC70;
    while ( (UFG::qOpRegistry *)v22 != &sOpsInstance )
    {
      if ( *(_QWORD *)v22 >= v21 )
      {
        if ( *(_QWORD *)v22 <= v21 )
        {
          if ( v22 )
          {
            v23 = *((_QWORD *)v20 + 1);
            if ( v23 )
              v24 = &v20[v23 + 8];
            else
              v24 = 0i64;
            (*(void (__fastcall **)(char *))(v22 + 56))(v24);
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
  for ( m = 0; m < this->mArrayCount; ++m )
  {
    v26 = this->mArrayTable.mOffset;
    if ( v26 )
      v27 = (char *)&this->mArrayTable + v26;
    else
      v27 = 0i64;
    v28 = &v27[24 * m];
    if ( *(_QWORD *)v28 )
      v29 = &v28[*(_QWORD *)v28];
    else
      v29 = 0i64;
    *((_QWORD *)v29 + 1) = 0i64;
    *(_QWORD *)v29 = 0i64;
  }
  for ( n = 0; n < this->mPatchCount; ++n )
  {
    v31 = this->mPatchTable.mOffset;
    if ( v31 )
      v32 = (char *)&this->mPatchTable + v31;
    else
      v32 = 0i64;
    v33 = &v32[16 * n];
    if ( *(_QWORD *)v33 )
      v34 = &v33[*(_QWORD *)v33];
    else
      v34 = 0i64;
    *(_QWORD *)v34 = 0i64;
  }
}

// File Line: 238
// RVA: 0x14681E0
__int64 UFG::_dynamic_initializer_for__gqReflectResourceInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gqReflectResourceInventory,
    "qReflectResourceInventory",
    0x5B00F999u,
    0x616A903Fu,
    0,
    0);
  UFG::gqReflectResourceInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::qReflectResourceInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gqReflectResourceInventory__);
}

// File Line: 246
// RVA: 0x1656B0
void __fastcall UFG::qReflectResourceInventory::Add(
        UFG::qReflectResourceInventory *this,
        UFG::qReflectResource *resource_data)
{
  UFG::qReflectResource *v4; // rcx

  v4 = 0i64;
  if ( resource_data )
  {
    resource_data->mNode.mParent = 0i64;
    resource_data->mNode.mChild[0] = 0i64;
    resource_data->mNode.mChild[1] = 0i64;
    resource_data->mResourceHandles.UFG::qResourceData::mNode.mPrev = &resource_data->mResourceHandles.UFG::qResourceData::mNode;
    resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext = &resource_data->mResourceHandles.UFG::qResourceData::mNode;
    v4 = resource_data;
  }
  UFG::qReflectResource::Construct(v4);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 255
// RVA: 0x17A310
void __fastcall UFG::qReflectResourceInventory::Remove(
        UFG::qReflectResourceInventory *this,
        UFG::qReflectResource *resource_data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  UFG::qResourceInventory::Remove(this, resource_data);
  UFG::qReflectResource::Destroy(resource_data);
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&resource_data->mResourceHandles);
  mPrev = resource_data->mResourceHandles.UFG::qResourceData::mNode.mPrev;
  mNext = resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  resource_data->mResourceHandles.UFG::qResourceData::mNode.mPrev = &resource_data->mResourceHandles.UFG::qResourceData::mNode;
  resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext = &resource_data->mResourceHandles.UFG::qResourceData::mNode;
}

