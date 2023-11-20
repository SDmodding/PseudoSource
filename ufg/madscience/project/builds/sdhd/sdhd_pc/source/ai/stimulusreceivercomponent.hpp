// File Line: 73
// RVA: 0x34ED20
void __fastcall UFG::ReceivedStimulusInfo::Clear(UFG::ReceivedStimulusInfo *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v1; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = &this->m_LastTimeReceived.m_pProducer;
  this->m_LastTimeReceived.m_Time = -99999.0;
  if ( this->m_LastTimeReceived.m_pProducer.m_pPointer )
  {
    v2 = v1->mPrev;
    v3 = this->m_LastTimeReceived.m_pProducer.mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    this->m_LastTimeReceived.m_pProducer.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->m_LastTimeReceived.m_pProducer.mPrev;
  }
  v4 = &this->m_LastTimePerceived.m_pProducer;
  this->m_LastTimeReceived.m_pProducer.m_pPointer = 0i64;
  this->m_LastTimePerceived.m_Time = -99999.0;
  if ( this->m_LastTimePerceived.m_pProducer.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v4->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = 0i64;
}

// File Line: 110
// RVA: 0x33B3F0
void __fastcall UFG::StimulusNotifyCallback::~StimulusNotifyCallback(UFG::StimulusNotifyCallback *this)
{
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v1; // rdx
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v2; // rcx
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v3; // rax

  this->vfptr = (UFG::StimulusNotifyCallbackVtbl *)&UFG::StimulusNotifyCallback::`vftable';
  v1 = (UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 129
// RVA: 0x33F6F0
UFG::ComponentIDDesc *__fastcall UFG::StimulusReceiverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::StimulusReceiverComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::StimulusReceiverComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::StimulusReceiverComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::StimulusReceiverComponent::_DescInit = 1;
    UFG::StimulusReceiverComponent::_TypeUID = UFG::StimulusReceiverComponent::_TypeIDesc.mChildBitMask | (UFG::StimulusReceiverComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::StimulusReceiverComponent::_StimulusReceiverComponentTypeUID = UFG::StimulusReceiverComponent::_TypeIDesc.mChildBitMask | (UFG::StimulusReceiverComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::StimulusReceiverComponent::_TypeIDesc;
}

