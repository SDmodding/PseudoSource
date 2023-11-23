// File Line: 26
// RVA: 0x4197E0
void __fastcall UFG::SpawnedRacket::SpawnedRacket(UFG::SpawnedRacket *this, unsigned int racketId)
{
  this->vfptr = (UFG::SpawnedRacketVtbl *)&UFG::SpawnedRacket::`vftable;
  this->mRacketID = racketId;
  UFG::RacketInstance2::RacketInstance2(&this->mRacket);
  this->m_PrefabInstances.p = 0i64;
  *(_QWORD *)&this->m_PrefabInstances.size = 0i64;
  this->m_ExteriorCorePrefabInstance.mPrev = &this->m_ExteriorCorePrefabInstance;
  this->m_ExteriorCorePrefabInstance.mNext = &this->m_ExteriorCorePrefabInstance;
  this->m_ExteriorCorePrefabInstance.m_pPointer = 0i64;
  this->m_ExteriorCoreDoorsPrefabInstance.mPrev = &this->m_ExteriorCoreDoorsPrefabInstance;
  this->m_ExteriorCoreDoorsPrefabInstance.mNext = &this->m_ExteriorCoreDoorsPrefabInstance;
  this->m_ExteriorCoreDoorsPrefabInstance.m_pPointer = 0i64;
  this->m_InteriorCoreDoorsPrefabInstance.mPrev = &this->m_InteriorCoreDoorsPrefabInstance;
  this->m_InteriorCoreDoorsPrefabInstance.mNext = &this->m_InteriorCoreDoorsPrefabInstance;
  this->m_InteriorCoreDoorsPrefabInstance.m_pPointer = 0i64;
  this->m_GameplayPrefabInstance.mPrev = &this->m_GameplayPrefabInstance;
  this->m_GameplayPrefabInstance.mNext = &this->m_GameplayPrefabInstance;
  this->m_GameplayPrefabInstance.m_pPointer = 0i64;
  this->m_AmbientPrefabInstance.mPrev = &this->m_AmbientPrefabInstance;
  this->m_AmbientPrefabInstance.mNext = &this->m_AmbientPrefabInstance;
  this->m_AmbientPrefabInstance.m_pPointer = 0i64;
}

// File Line: 28
// RVA: 0x419B60
void __fastcall UFG::SpawnedRacket::~SpawnedRacket(UFG::SpawnedRacket *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p_m_AmbientPrefabInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p_m_GameplayPrefabInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p_m_InteriorCoreDoorsPrefabInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p_m_ExteriorCoreDoorsPrefabInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p_m_ExteriorCorePrefabInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p; // rcx
  UFG::SimComponent **p_m_pPointer; // rbx

  this->vfptr = (UFG::SpawnedRacketVtbl *)&UFG::SpawnedRacket::`vftable;
  p_m_AmbientPrefabInstance = &this->m_AmbientPrefabInstance;
  if ( this->m_AmbientPrefabInstance.m_pPointer )
  {
    mPrev = p_m_AmbientPrefabInstance->mPrev;
    mNext = p_m_AmbientPrefabInstance->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_AmbientPrefabInstance->mPrev = p_m_AmbientPrefabInstance;
    p_m_AmbientPrefabInstance->mNext = p_m_AmbientPrefabInstance;
  }
  p_m_AmbientPrefabInstance->m_pPointer = 0i64;
  v5 = p_m_AmbientPrefabInstance->mPrev;
  v6 = p_m_AmbientPrefabInstance->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_AmbientPrefabInstance->mPrev = p_m_AmbientPrefabInstance;
  p_m_AmbientPrefabInstance->mNext = p_m_AmbientPrefabInstance;
  p_m_GameplayPrefabInstance = &this->m_GameplayPrefabInstance;
  if ( this->m_GameplayPrefabInstance.m_pPointer )
  {
    v8 = p_m_GameplayPrefabInstance->mPrev;
    v9 = this->m_GameplayPrefabInstance.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_GameplayPrefabInstance->mPrev = p_m_GameplayPrefabInstance;
    this->m_GameplayPrefabInstance.mNext = &this->m_GameplayPrefabInstance;
  }
  this->m_GameplayPrefabInstance.m_pPointer = 0i64;
  v10 = p_m_GameplayPrefabInstance->mPrev;
  v11 = this->m_GameplayPrefabInstance.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_GameplayPrefabInstance->mPrev = p_m_GameplayPrefabInstance;
  this->m_GameplayPrefabInstance.mNext = &this->m_GameplayPrefabInstance;
  p_m_InteriorCoreDoorsPrefabInstance = &this->m_InteriorCoreDoorsPrefabInstance;
  if ( this->m_InteriorCoreDoorsPrefabInstance.m_pPointer )
  {
    v13 = p_m_InteriorCoreDoorsPrefabInstance->mPrev;
    v14 = this->m_InteriorCoreDoorsPrefabInstance.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_InteriorCoreDoorsPrefabInstance->mPrev = p_m_InteriorCoreDoorsPrefabInstance;
    this->m_InteriorCoreDoorsPrefabInstance.mNext = &this->m_InteriorCoreDoorsPrefabInstance;
  }
  this->m_InteriorCoreDoorsPrefabInstance.m_pPointer = 0i64;
  v15 = p_m_InteriorCoreDoorsPrefabInstance->mPrev;
  v16 = this->m_InteriorCoreDoorsPrefabInstance.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_InteriorCoreDoorsPrefabInstance->mPrev = p_m_InteriorCoreDoorsPrefabInstance;
  this->m_InteriorCoreDoorsPrefabInstance.mNext = &this->m_InteriorCoreDoorsPrefabInstance;
  p_m_ExteriorCoreDoorsPrefabInstance = &this->m_ExteriorCoreDoorsPrefabInstance;
  if ( this->m_ExteriorCoreDoorsPrefabInstance.m_pPointer )
  {
    v18 = p_m_ExteriorCoreDoorsPrefabInstance->mPrev;
    v19 = this->m_ExteriorCoreDoorsPrefabInstance.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_m_ExteriorCoreDoorsPrefabInstance->mPrev = p_m_ExteriorCoreDoorsPrefabInstance;
    this->m_ExteriorCoreDoorsPrefabInstance.mNext = &this->m_ExteriorCoreDoorsPrefabInstance;
  }
  this->m_ExteriorCoreDoorsPrefabInstance.m_pPointer = 0i64;
  v20 = p_m_ExteriorCoreDoorsPrefabInstance->mPrev;
  v21 = this->m_ExteriorCoreDoorsPrefabInstance.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  p_m_ExteriorCoreDoorsPrefabInstance->mPrev = p_m_ExteriorCoreDoorsPrefabInstance;
  this->m_ExteriorCoreDoorsPrefabInstance.mNext = &this->m_ExteriorCoreDoorsPrefabInstance;
  p_m_ExteriorCorePrefabInstance = &this->m_ExteriorCorePrefabInstance;
  if ( this->m_ExteriorCorePrefabInstance.m_pPointer )
  {
    v23 = p_m_ExteriorCorePrefabInstance->mPrev;
    v24 = this->m_ExteriorCorePrefabInstance.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    p_m_ExteriorCorePrefabInstance->mPrev = p_m_ExteriorCorePrefabInstance;
    this->m_ExteriorCorePrefabInstance.mNext = &this->m_ExteriorCorePrefabInstance;
  }
  this->m_ExteriorCorePrefabInstance.m_pPointer = 0i64;
  v25 = p_m_ExteriorCorePrefabInstance->mPrev;
  v26 = this->m_ExteriorCorePrefabInstance.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  p_m_ExteriorCorePrefabInstance->mPrev = p_m_ExteriorCorePrefabInstance;
  this->m_ExteriorCorePrefabInstance.mNext = &this->m_ExteriorCorePrefabInstance;
  p = this->m_PrefabInstances.p;
  if ( p )
  {
    p_m_pPointer = &p[-1].m_pPointer;
    `eh vector destructor iterator(
      p,
      0x18ui64,
      (int)p[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
    operator delete[](p_m_pPointer);
  }
  this->m_PrefabInstances.p = 0i64;
  *(_QWORD *)&this->m_PrefabInstances.size = 0i64;
  UFG::qReflectHandleBase::~qReflectHandleBase(&this->mRacket.mType);
}

