// File Line: 19
// RVA: 0x41BB10
void __fastcall UFG::TurfInstance::Init(UFG::TurfInstance *this, unsigned int playerID)
{
  UFG::TurfInstanceData *TurfInstanceDataForPlayerId; // rax
  UFG::TurfInstanceData *v4; // rbx
  UFG::TurfComponent *p_mNext; // rdx
  UFG::qList<UFG::TurfComponent,UFG::TurfComponent,1,0> *v6; // rcx
  UFG::qReflectHandleBase *TurfTemplate; // rax
  _BYTE result[48]; // [rsp+28h] [rbp-30h] BYREF

  TurfInstanceDataForPlayerId = UFG::PlaceholderGameDB::GetTurfInstanceDataForPlayerId(
                                  UFG::PlaceholderGameDB::ms_pSingleton,
                                  playerID);
  v4 = TurfInstanceDataForPlayerId;
  this->mData = TurfInstanceDataForPlayerId;
  if ( TurfInstanceDataForPlayerId )
  {
    if ( TurfInstanceDataForPlayerId->locationName.mStringHash32 == -1 )
      TurfInstanceDataForPlayerId->locationName.mStringHash32 = UFG::qStringHash32(
                                                                  TurfInstanceDataForPlayerId->locationName.mData,
                                                                  0xFFFFFFFF);
    p_mNext = (UFG::TurfComponent *)&UFG::TurfComponent::s_TurfComponentList.mNode.mNext[-5].mNext;
    if ( &UFG::TurfComponent::s_TurfComponentList.mNode.mNext[-5].mNext == (UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> **)((char *)&UFG::TurfComponent::s_TurfComponentList - 72) )
    {
LABEL_7:
      p_mNext = 0i64;
    }
    else
    {
      while ( 1 )
      {
        v6 = (UFG::qList<UFG::TurfComponent,UFG::TurfComponent,1,0> *)&p_mNext->mNext[-5].mNext;
        if ( p_mNext->m_pSimObject->m_Name.mUID == v4->locationName.mStringHash32 )
          break;
        p_mNext = (UFG::TurfComponent *)&p_mNext->mNext[-5].mNext;
        if ( v6 == (UFG::qList<UFG::TurfComponent,UFG::TurfComponent,1,0> *)((char *)&UFG::TurfComponent::s_TurfComponentList
                                                                           - 72) )
          goto LABEL_7;
      }
    }
    this->mComponent = p_mNext;
    TurfTemplate = (UFG::qReflectHandleBase *)UFG::TurfManager::GetTurfTemplate(
                                                (UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *)result,
                                                this->mData->templateName.mData);
    UFG::qReflectHandleBase::operator=(&this->mTemplate, TurfTemplate);
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)result);
  }
}

