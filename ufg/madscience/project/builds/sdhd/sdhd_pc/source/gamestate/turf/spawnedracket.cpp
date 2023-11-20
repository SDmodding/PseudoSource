// File Line: 44
// RVA: 0x41C760
void __fastcall UFG::SpawnedRacket::SetGameplayPrefabInstance(UFG::SpawnedRacket *this, UFG::SceneObjectProperties *prefabInstance)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_GameplayPrefabInstance.mPrev;
  if ( this->m_GameplayPrefabInstance.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
  }
  v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)prefabInstance;
  if ( prefabInstance )
  {
    v5 = prefabInstance->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    v2->mNext = &prefabInstance->m_SafePointerList.mNode;
    prefabInstance->m_SafePointerList.mNode.mPrev = v2;
  }
}

// File Line: 49
// RVA: 0x41C710
void __fastcall UFG::SpawnedRacket::SetAmbientPrefabInstance(UFG::SpawnedRacket *this, UFG::SceneObjectProperties *prefabInstance)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_AmbientPrefabInstance.mPrev;
  if ( this->m_AmbientPrefabInstance.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
  }
  v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)prefabInstance;
  if ( prefabInstance )
  {
    v5 = prefabInstance->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    v2->mNext = &prefabInstance->m_SafePointerList.mNode;
    prefabInstance->m_SafePointerList.mNode.mPrev = v2;
  }
}

