// File Line: 26
// RVA: 0x4197E0
void __fastcall UFG::SpawnedRacket::SpawnedRacket(UFG::SpawnedRacket *this, unsigned int racketId)
{
  UFG::SpawnedRacket *v2; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v3; // [rsp+50h] [rbp+18h]
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v4; // [rsp+50h] [rbp+18h]
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v5; // [rsp+50h] [rbp+18h]
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v6; // [rsp+50h] [rbp+18h]
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v7; // [rsp+50h] [rbp+18h]

  v2 = this;
  this->vfptr = (UFG::SpawnedRacketVtbl *)&UFG::SpawnedRacket::`vftable';
  this->mRacketID = racketId;
  UFG::RacketInstance2::RacketInstance2(&this->mRacket);
  v2->m_PrefabInstances.p = 0i64;
  *(_QWORD *)&v2->m_PrefabInstances.size = 0i64;
  v3 = &v2->m_ExteriorCorePrefabInstance;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v2->m_ExteriorCorePrefabInstance.m_pPointer = 0i64;
  v4 = &v2->m_ExteriorCoreDoorsPrefabInstance;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v2->m_ExteriorCoreDoorsPrefabInstance.m_pPointer = 0i64;
  v5 = &v2->m_InteriorCoreDoorsPrefabInstance;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v2->m_InteriorCoreDoorsPrefabInstance.m_pPointer = 0i64;
  v6 = &v2->m_GameplayPrefabInstance;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v2->m_GameplayPrefabInstance.m_pPointer = 0i64;
  v7 = &v2->m_AmbientPrefabInstance;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v2->m_AmbientPrefabInstance.m_pPointer = 0i64;
}

// File Line: 28
// RVA: 0x419B60
void __fastcall UFG::SpawnedRacket::~SpawnedRacket(UFG::SpawnedRacket *this)
{
  UFG::qReflectHandleBase *v1; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  unsigned __int64 *v7; // rdx
  unsigned __int64 v8; // rcx
  _QWORD *v9; // rax
  unsigned __int64 v10; // rcx
  _QWORD *v11; // rax
  UFG::qReflectObject **v12; // rdx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v13; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v14; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v15; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v16; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> **v17; // rdx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v18; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v19; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v20; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v21; // rax
  unsigned __int64 *v22; // rdx
  UFG::qReflectObjectVtbl *v23; // rcx
  UFG::qReflectObject *v24; // rax
  UFG::qReflectObjectVtbl *v25; // rcx
  UFG::qReflectObject *v26; // rax
  char *v27; // rcx
  char *v28; // rbx

  v1 = (UFG::qReflectHandleBase *)this;
  this->vfptr = (UFG::SpawnedRacketVtbl *)&UFG::SpawnedRacket::`vftable';
  v2 = &this->m_AmbientPrefabInstance;
  if ( this->m_AmbientPrefabInstance.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = &v1[4].mTypeUID;
  if ( v1[4].mData )
  {
    v8 = *v7;
    v9 = (_QWORD *)v1[4].mNameUID;
    *(_QWORD *)(v8 + 8) = v9;
    *v9 = v8;
    *v7 = (unsigned __int64)v7;
    v1[4].mNameUID = (unsigned __int64)&v1[4].mTypeUID;
  }
  v1[4].mData = 0i64;
  v10 = *v7;
  v11 = (_QWORD *)v1[4].mNameUID;
  *(_QWORD *)(v10 + 8) = v11;
  *v11 = v10;
  *v7 = (unsigned __int64)v7;
  v1[4].mNameUID = (unsigned __int64)&v1[4].mTypeUID;
  v12 = &v1[3].mData;
  if ( v1[4].mNext )
  {
    v13 = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)*v12;
    v14 = v1[4].mPrev;
    v13->mNext = v14;
    v14->mPrev = v13;
    *v12 = (UFG::qReflectObject *)v12;
    v1[4].mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v1[3].mData;
  }
  v1[4].mNext = 0i64;
  v15 = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)*v12;
  v16 = v1[4].mPrev;
  v15->mNext = v16;
  v16->mPrev = v15;
  *v12 = (UFG::qReflectObject *)v12;
  v1[4].mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v1[3].mData;
  v17 = &v1[3].mNext;
  if ( v1[3].mNameUID )
  {
    v18 = *v17;
    v19 = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)v1[3].mTypeUID;
    v18->mNext = v19;
    v19->mPrev = v18;
    *v17 = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)v17;
    v1[3].mTypeUID = (unsigned __int64)&v1[3].mNext;
  }
  v1[3].mNameUID = 0i64;
  v20 = *v17;
  v21 = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)v1[3].mTypeUID;
  v20->mNext = v21;
  v21->mPrev = v20;
  *v17 = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)v17;
  v1[3].mTypeUID = (unsigned __int64)&v1[3].mNext;
  v22 = &v1[2].mNameUID;
  if ( v1[3].mPrev )
  {
    v23 = (UFG::qReflectObjectVtbl *)*v22;
    v24 = v1[2].mData;
    v23->GetTypeName = (const char *(__fastcall *)(UFG::qReflectObject *))v24;
    v24->vfptr = v23;
    *v22 = (unsigned __int64)v22;
    v1[2].mData = (UFG::qReflectObject *)&v1[2].mNameUID;
  }
  v1[3].mPrev = 0i64;
  v25 = (UFG::qReflectObjectVtbl *)*v22;
  v26 = v1[2].mData;
  v25->GetTypeName = (const char *(__fastcall *)(UFG::qReflectObject *))v26;
  v26->vfptr = v25;
  *v22 = (unsigned __int64)v22;
  v1[2].mData = (UFG::qReflectObject *)&v1[2].mNameUID;
  v27 = (char *)v1[2].mTypeUID;
  if ( v27 )
  {
    v28 = v27 - 8;
    `eh vector destructor iterator'(
      v27,
      0x18ui64,
      *((_DWORD *)v27 - 2),
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
    operator delete[](v28);
  }
  v1[2].mTypeUID = 0i64;
  v1[2].mNext = 0i64;
  UFG::qReflectHandleBase::~qReflectHandleBase(v1 + 1);
}

