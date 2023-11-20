// File Line: 16
// RVA: 0x14679D0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::qReflectOnDemandCacheItem_UFG::qReflectObject_::sDeserializeOp__()
{
  const char *v0; // r8
  unsigned __int64 v1; // rax
  char v2; // cl
  UFG::qOpRegistry *v3; // rax

  v0 = "UFG::qReflectOnDemandCacheItem";
  v1 = -1i64;
  v2 = 85;
  do
  {
    ++v0;
    v1 = (v1 >> 8) ^ sCrcTable64[(unsigned __int8)(v1 ^ v2)];
    v2 = *v0;
  }
  while ( *v0 );
  UFG::qReflectObjectType<UFG::qReflectOnDemandCacheItem,UFG::qReflectObject>::sDeserializeOp.mBaseNode.mUID = v1;
  v3 = UFG::qOpRegistry::Instance();
  UFG::qTree64Base::Add(
    &v3->mOpTree.mTree,
    &UFG::qReflectObjectType<UFG::qReflectOnDemandCacheItem,UFG::qReflectObject>::sDeserializeOp.mBaseNode);
}

// File Line: 31
// RVA: 0x167950
void __fastcall UFG::qReflectOnDemandVisitor::BeginObject(UFG::qReflectOnDemandVisitor *this, UFG::qReflectType *reflection_type, const char *object_data)
{
  const char *v3; // r10
  unsigned __int64 v4; // r9
  char v5; // al
  unsigned __int64 v6; // rdx

  v3 = "UFG::qReflectHandleBase";
  v4 = -1i64;
  v5 = 85;
  do
  {
    ++v3;
    v4 = (v4 >> 8) ^ sCrcTable64[(unsigned __int8)(v4 ^ v5)];
    v5 = *v3;
  }
  while ( *v3 );
  if ( reflection_type->mBaseNode.mUID == v4 )
  {
    v6 = *((_QWORD *)object_data + 3);
    if ( v6 )
    {
      if ( !*((_QWORD *)object_data + 4) )
        UFG::qReflectOnDemandLoader::LoadCachedReferences(*((_QWORD *)object_data + 2), v6, 0i64, 0i64);
    }
  }
}

// File Line: 108
// RVA: 0x176C60
void __fastcall UFG::qReflectOnDemandLoader::LoadCachedReferences(UFG::qReflectObject *obj)
{
  UFG::qReflectObject *v1; // rdi
  unsigned __int64 v2; // rbx
  UFG::ReflectionDB *v3; // rax
  UFG::qReflectType *v4; // rdx
  UFG::qReflectVisitor v5; // [rsp+28h] [rbp-40h]

  v1 = obj;
  v2 = obj->mTypeUID;
  v3 = UFG::ReflectionDB::Instance();
  v4 = (UFG::qReflectType *)v3->mTypes.mTree.mHead.mChildren[0];
  while ( v4 != (UFG::qReflectType *)&v3->mTypes )
  {
    if ( v4->mBaseNode.mUID >= v2 )
    {
      if ( v4->mBaseNode.mUID <= v2 )
        goto LABEL_8;
      v4 = (UFG::qReflectType *)v4->mBaseNode.mChildren[0];
    }
    else
    {
      v4 = (UFG::qReflectType *)v4->mBaseNode.mChildren[1];
    }
  }
  v4 = 0i64;
LABEL_8:
  v5.mTrackedObjects.p = 0i64;
  *(_QWORD *)&v5.mTrackedObjects.size = 0i64;
  v5.mPatches.p = 0i64;
  *(_QWORD *)&v5.mPatches.size = 0i64;
  v5.mArrays.p = 0i64;
  *(_QWORD *)&v5.mArrays.size = 0i64;
  v5.vfptr = (UFG::qReflectVisitorVtbl *)&UFG::qReflectOnDemandVisitor::`vftable';
  UFG::qReflectVisitor::TrackObject(&v5, v4, (const char *)v1);
  UFG::qReflectVisitor::VisitObjects(&v5);
  UFG::qReflectVisitor::~qReflectVisitor(&v5);
}

// File Line: 122
// RVA: 0x176D10
void __fastcall UFG::qReflectOnDemandLoader::LoadCachedReferences(unsigned __int64 type_uid, unsigned __int64 name_uid, void (__fastcall *callback)(void *), void *callback_param)
{
  void *v4; // r14
  void (__fastcall *v5)(void *); // r15
  unsigned __int64 v6; // rbp
  unsigned __int64 v7; // rbx
  UFG::qReflectWarehouse *v8; // rax
  UFG::qReflectWarehouse *v9; // r10
  unsigned int v10; // edi
  UFG::qReflectInventoryBase *v11; // rcx
  const char *v12; // rsi
  const char *v13; // rdx
  unsigned __int64 v14; // rbx
  char v15; // al
  UFG::qReflectWarehouse *v16; // rax
  UFG::qReflectWarehouse *v17; // rcx
  UFG::qReflectInventoryBase *v18; // rcx
  UFG::qReflectObject *v19; // rax
  UFG::qReflectObject *v20; // rsi
  char v21; // bp
  unsigned __int64 v22; // rcx
  char *v23; // rbx
  unsigned __int64 v24; // rax
  UFG::qReflectOnDemandLoader::RequestCallback *v25; // rax
  signed __int64 v26; // rax
  const char *v27; // rcx
  UFG::ReflectionDB *v28; // rax
  UFG::qReflectType *v29; // rdx
  UFG::qReflectVisitor v30; // [rsp+30h] [rbp-58h]

  v4 = callback_param;
  v5 = callback;
  v6 = name_uid;
  v7 = type_uid;
  v8 = UFG::qReflectWarehouse::Instance();
  v9 = (UFG::qReflectWarehouse *)v8->mInventoryTree.mTree.mHead.mChildren[0];
  v10 = 0;
  while ( v9 != v8 )
  {
    if ( v9->mInventoryTree.mTree.mHead.mUID >= v7 )
    {
      if ( v9->mInventoryTree.mTree.mHead.mUID <= v7 )
      {
        v11 = (UFG::qReflectInventoryBase *)&v9[-1].mInventoryTree.mTree.mCount;
        goto LABEL_10;
      }
      v9 = (UFG::qReflectWarehouse *)v9->mInventoryTree.mTree.mHead.mChildren[0];
    }
    else
    {
      v9 = (UFG::qReflectWarehouse *)v9->mInventoryTree.mTree.mHead.mChildren[1];
    }
  }
  v11 = 0i64;
LABEL_10:
  v12 = (const char *)UFG::qReflectInventoryBase::FindObject(v11, v6);
  if ( v12 )
  {
    v28 = UFG::ReflectionDB::Instance();
    v29 = (UFG::qReflectType *)v28->mTypes.mTree.mHead.mChildren[0];
    while ( v29 != (UFG::qReflectType *)&v28->mTypes )
    {
      if ( v29->mBaseNode.mUID >= v7 )
      {
        if ( v29->mBaseNode.mUID <= v7 )
          goto LABEL_52;
        v29 = (UFG::qReflectType *)v29->mBaseNode.mChildren[0];
      }
      else
      {
        v29 = (UFG::qReflectType *)v29->mBaseNode.mChildren[1];
      }
    }
    v29 = 0i64;
LABEL_52:
    v30.mTrackedObjects.p = 0i64;
    *(_QWORD *)&v30.mTrackedObjects.size = 0i64;
    v30.mPatches.p = 0i64;
    *(_QWORD *)&v30.mPatches.size = 0i64;
    v30.mArrays.p = 0i64;
    *(_QWORD *)&v30.mArrays.size = 0i64;
    v30.vfptr = (UFG::qReflectVisitorVtbl *)&UFG::qReflectOnDemandVisitor::`vftable';
    UFG::qReflectVisitor::TrackObject(&v30, v29, v12);
    UFG::qReflectVisitor::VisitObjects(&v30);
    UFG::qReflectVisitor::~qReflectVisitor(&v30);
    return;
  }
  v13 = "UFG::qReflectOnDemandCacheItem";
  v14 = -1i64;
  v15 = 85;
  do
  {
    v14 = (v14 >> 8) ^ sCrcTable64[(unsigned __int8)(v14 ^ v15)];
    v15 = *++v13;
  }
  while ( *v13 );
  v16 = UFG::qReflectWarehouse::Instance();
  v17 = (UFG::qReflectWarehouse *)v16->mInventoryTree.mTree.mHead.mChildren[0];
  if ( v17 == v16 )
  {
LABEL_21:
    v18 = 0i64;
    goto LABEL_22;
  }
  while ( v17->mInventoryTree.mTree.mHead.mUID < v14 )
  {
    v17 = (UFG::qReflectWarehouse *)v17->mInventoryTree.mTree.mHead.mChildren[1];
LABEL_18:
    if ( v17 == v16 )
      goto LABEL_21;
  }
  if ( v17->mInventoryTree.mTree.mHead.mUID > v14 )
  {
    v17 = (UFG::qReflectWarehouse *)v17->mInventoryTree.mTree.mHead.mChildren[0];
    goto LABEL_18;
  }
  v18 = (UFG::qReflectInventoryBase *)&v17[-1].mInventoryTree.mTree.mCount;
LABEL_22:
  v19 = UFG::qReflectInventoryBase::FindObject(v18, v6);
  v20 = v19;
  if ( v19 )
  {
    v21 = 0;
    v22 = v19->mBaseNode.mUID;
    v23 = (char *)UFG::qReflectOnDemandLoader::sLoadRequests.mTree.mHead.mChildren[0];
    while ( v23 != (char *)&UFG::qReflectOnDemandLoader::sLoadRequests )
    {
      if ( *(_QWORD *)v23 >= v22 )
      {
        if ( *(_QWORD *)v23 <= v22 )
          goto LABEL_30;
        v23 = (char *)*((_QWORD *)v23 + 2);
      }
      else
      {
        v23 = (char *)*((_QWORD *)v23 + 3);
      }
    }
    v23 = 0i64;
LABEL_30:
    if ( !v23 )
    {
      v21 = 1;
      v23 = AMemory::malloc_default(0x48ui64);
      if ( v23 )
      {
        v24 = v20->mBaseNode.mUID;
        *((_QWORD *)v23 + 1) = v23;
        *((_QWORD *)v23 + 2) = v23;
        *((_QWORD *)v23 + 3) = v23;
        *((_QWORD *)v23 + 4) = v23;
        *((_QWORD *)v23 + 5) = v23;
        *(_QWORD *)v23 = v24;
        *((_QWORD *)v23 + 6) = v20;
        *((_QWORD *)v23 + 8) = 0i64;
        *((_QWORD *)v23 + 7) = 0i64;
      }
      else
      {
        v23 = 0i64;
      }
      UFG::qTree64Base::Add(&UFG::qReflectOnDemandLoader::sLoadRequests.mTree, (UFG::qTree64Base::BaseNode *)v23);
    }
    if ( v5 && v4 )
    {
      v25 = UFG::qArray<UFG::qReflectOnDemandLoader::RequestCallback,0>::Add(
              (UFG::qArray<UFG::qReflectOnDemandLoader::RequestCallback,0> *)(v23 + 56),
              "qArray.Add");
      v25->Callback = v5;
      v25->CallbackParam = v4;
    }
    if ( v21 == 1 && LODWORD(v20[1].mBaseNode.mParent) )
    {
      do
      {
        v26 = v20[1].mBaseNode.mUID + 16i64 * v10;
        if ( *(_DWORD *)(v26 + 8) )
          v27 = *(const char **)v26;
        else
          v27 = &customWorldMapCaption;
        UFG::qReflectOnDemandLoader::sLoadFileCallback(v27, v23);
        ++v10;
      }
      while ( v10 < LODWORD(v20[1].mBaseNode.mParent) );
    }
  }
}

