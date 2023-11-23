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
void __fastcall UFG::qReflectOnDemandVisitor::BeginObject(
        UFG::qReflectOnDemandVisitor *this,
        UFG::qReflectType *reflection_type,
        const char *object_data)
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
  unsigned __int64 mTypeUID; // rbx
  UFG::ReflectionDB *v3; // rax
  UFG::qReflectType *v4; // rdx
  UFG::qReflectVisitor v5; // [rsp+28h] [rbp-40h] BYREF

  mTypeUID = obj->mTypeUID;
  v3 = UFG::ReflectionDB::Instance();
  v4 = (UFG::qReflectType *)v3->mTypes.mTree.mHead.mChildren[0];
  while ( v4 != (UFG::qReflectType *)&v3->mTypes )
  {
    if ( v4->mBaseNode.mUID >= mTypeUID )
    {
      if ( v4->mBaseNode.mUID <= mTypeUID )
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
  memset(&v5.mTrackedObjects, 0, 48);
  v5.vfptr = (UFG::qReflectVisitorVtbl *)&UFG::qReflectOnDemandVisitor::`vftable;
  UFG::qReflectVisitor::TrackObject(&v5, v4, (const char *)obj);
  UFG::qReflectVisitor::VisitObjects(&v5);
  UFG::qReflectVisitor::~qReflectVisitor(&v5);
}

// File Line: 122
// RVA: 0x176D10
void __fastcall UFG::qReflectOnDemandLoader::LoadCachedReferences(
        unsigned __int64 type_uid,
        UFG::qReflectInventoryBaseVtbl *name_uid,
        void (__fastcall *callback)(void *),
        void *callback_param)
{
  UFG::qReflectWarehouse *v8; // rax
  UFG::qReflectWarehouse *v9; // r10
  unsigned int v10; // edi
  UFG::qReflectInventoryBase *p_mCount; // rcx
  UFG::qReflectObject *Object; // rsi
  const char *v13; // rdx
  unsigned __int64 v14; // rbx
  char v15; // al
  UFG::qReflectWarehouse *v16; // rax
  UFG::qReflectWarehouse *v17; // rcx
  UFG::qReflectInventoryBase *v18; // rcx
  UFG::qReflectObject *v19; // rax
  UFG::qReflectObject *v20; // rsi
  char v21; // bp
  unsigned __int64 mUID; // rcx
  char *v23; // rbx
  unsigned __int64 v24; // rax
  UFG::qReflectOnDemandLoader::RequestCallback *v25; // rax
  __int64 v26; // rax
  const char *v27; // rcx
  UFG::ReflectionDB *v28; // rax
  UFG::qReflectType *v29; // rdx
  UFG::qReflectVisitor v30; // [rsp+30h] [rbp-58h] BYREF

  v8 = UFG::qReflectWarehouse::Instance();
  v9 = (UFG::qReflectWarehouse *)v8->mInventoryTree.mTree.mHead.mChildren[0];
  v10 = 0;
  while ( v9 != v8 )
  {
    if ( v9->mInventoryTree.mTree.mHead.mUID >= type_uid )
    {
      if ( v9->mInventoryTree.mTree.mHead.mUID <= type_uid )
      {
        p_mCount = (UFG::qReflectInventoryBase *)&v9[-1].mInventoryTree.mTree.mCount;
        goto LABEL_10;
      }
      v9 = (UFG::qReflectWarehouse *)v9->mInventoryTree.mTree.mHead.mChildren[0];
    }
    else
    {
      v9 = (UFG::qReflectWarehouse *)v9->mInventoryTree.mTree.mHead.mChildren[1];
    }
  }
  p_mCount = 0i64;
LABEL_10:
  Object = UFG::qReflectInventoryBase::FindObject(p_mCount, name_uid);
  if ( Object )
  {
    v28 = UFG::ReflectionDB::Instance();
    v29 = (UFG::qReflectType *)v28->mTypes.mTree.mHead.mChildren[0];
    while ( v29 != (UFG::qReflectType *)&v28->mTypes )
    {
      if ( v29->mBaseNode.mUID >= type_uid )
      {
        if ( v29->mBaseNode.mUID <= type_uid )
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
    memset(&v30.mTrackedObjects, 0, 48);
    v30.vfptr = (UFG::qReflectVisitorVtbl *)&UFG::qReflectOnDemandVisitor::`vftable;
    UFG::qReflectVisitor::TrackObject(&v30, v29, (const char *)Object);
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
  v19 = UFG::qReflectInventoryBase::FindObject(v18, name_uid);
  v20 = v19;
  if ( v19 )
  {
    v21 = 0;
    mUID = v19->mBaseNode.mUID;
    v23 = (char *)UFG::qReflectOnDemandLoader::sLoadRequests.mTree.mHead.mChildren[0];
    while ( v23 != (char *)&UFG::qReflectOnDemandLoader::sLoadRequests )
    {
      if ( *(_QWORD *)v23 >= mUID )
      {
        if ( *(_QWORD *)v23 <= mUID )
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
    if ( callback && callback_param )
    {
      v25 = UFG::qArray<UFG::qReflectOnDemandLoader::RequestCallback,0>::Add(
              (UFG::qArray<UFG::qReflectOnDemandLoader::RequestCallback,0> *)(v23 + 56),
              "qArray.Add");
      v25->Callback = callback;
      v25->CallbackParam = callback_param;
    }
    if ( v21 == 1 && LODWORD(v20[1].mBaseNode.mParent) )
    {
      do
      {
        v26 = v20[1].mBaseNode.mUID + 16i64 * v10;
        if ( *(_DWORD *)(v26 + 8) )
          v27 = *(const char **)v26;
        else
          v27 = &customCaption;
        UFG::qReflectOnDemandLoader::sLoadFileCallback(v27, v23);
        ++v10;
      }
      while ( v10 < LODWORD(v20[1].mBaseNode.mParent) );
    }
  }
}

