// File Line: 44
// RVA: 0x41C760
void __fastcall UFG::SpawnedRacket::SetGameplayPrefabInstance(
        UFG::SpawnedRacket *this,
        UFG::SceneObjectProperties *prefabInstance)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p_m_GameplayPrefabInstance; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  p_m_GameplayPrefabInstance = &this->m_GameplayPrefabInstance;
  if ( this->m_GameplayPrefabInstance.m_pPointer )
  {
    mPrev = p_m_GameplayPrefabInstance->mPrev;
    mNext = p_m_GameplayPrefabInstance->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_GameplayPrefabInstance->mPrev = p_m_GameplayPrefabInstance;
    p_m_GameplayPrefabInstance->mNext = p_m_GameplayPrefabInstance;
  }
  p_m_GameplayPrefabInstance->m_pPointer = prefabInstance;
  if ( prefabInstance )
  {
    v5 = prefabInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v5->mNext = p_m_GameplayPrefabInstance;
    p_m_GameplayPrefabInstance->mPrev = v5;
    p_m_GameplayPrefabInstance->mNext = &prefabInstance->m_SafePointerList.mNode;
    prefabInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_GameplayPrefabInstance;
  }
}

// File Line: 49
// RVA: 0x41C710
void __fastcall UFG::SpawnedRacket::SetAmbientPrefabInstance(
        UFG::SpawnedRacket *this,
        UFG::SceneObjectProperties *prefabInstance)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p_m_AmbientPrefabInstance; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

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
  p_m_AmbientPrefabInstance->m_pPointer = prefabInstance;
  if ( prefabInstance )
  {
    v5 = prefabInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v5->mNext = p_m_AmbientPrefabInstance;
    p_m_AmbientPrefabInstance->mPrev = v5;
    p_m_AmbientPrefabInstance->mNext = &prefabInstance->m_SafePointerList.mNode;
    prefabInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_AmbientPrefabInstance;
  }
}

