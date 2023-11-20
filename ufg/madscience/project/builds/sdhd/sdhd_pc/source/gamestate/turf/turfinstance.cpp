// File Line: 19
// RVA: 0x41BB10
void __fastcall UFG::TurfInstance::Init(UFG::TurfInstance *this, unsigned int playerID)
{
  UFG::TurfInstance *v2; // rdi
  UFG::TurfInstanceData *v3; // rax
  UFG::TurfInstanceData *v4; // rbx
  UFG::TurfComponent *v5; // rdx
  UFG::qList<UFG::TurfComponent,UFG::TurfComponent,1,0> *v6; // rcx
  UFG::qReflectHandle<UFG::TurfTemplate> *v7; // rax
  UFG::qReflectHandle<UFG::TurfTemplate> result; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = UFG::PlaceholderGameDB::GetTurfInstanceDataForPlayerId(UFG::PlaceholderGameDB::ms_pSingleton, playerID);
  v4 = v3;
  v2->mData = v3;
  if ( v3 )
  {
    if ( v3->locationName.mStringHash32 == -1 )
      v3->locationName.mStringHash32 = UFG::qStringHash32(v3->locationName.mData, 0xFFFFFFFF);
    v5 = (UFG::TurfComponent *)&UFG::TurfComponent::s_TurfComponentList.mNode.mNext[-5].mNext;
    if ( &UFG::TurfComponent::s_TurfComponentList.mNode.mNext[-5].mNext == (UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> **)((char *)&UFG::TurfComponent::s_TurfComponentList - 72) )
    {
LABEL_7:
      v5 = 0i64;
    }
    else
    {
      while ( 1 )
      {
        v6 = (UFG::qList<UFG::TurfComponent,UFG::TurfComponent,1,0> *)&v5->mNext[-5].mNext;
        if ( v5->m_pSimObject->m_Name.mUID == v4->locationName.mStringHash32 )
          break;
        v5 = (UFG::TurfComponent *)&v5->mNext[-5].mNext;
        if ( v6 == (UFG::qList<UFG::TurfComponent,UFG::TurfComponent,1,0> *)((char *)&UFG::TurfComponent::s_TurfComponentList
                                                                           - 72) )
          goto LABEL_7;
      }
    }
    v2->mComponent = v5;
    v7 = UFG::TurfManager::GetTurfTemplate(&result, v2->mData->templateName.mData);
    UFG::qReflectHandleBase::operator=(
      (UFG::qReflectHandleBase *)&v2->mTemplate.mPrev,
      (UFG::qReflectHandleBase *)&v7->mPrev);
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mPrev);
  }
}

