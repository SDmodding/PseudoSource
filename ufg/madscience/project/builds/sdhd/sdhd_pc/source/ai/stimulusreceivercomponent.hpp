// File Line: 73
// RVA: 0x34ED20
void __fastcall UFG::ReceivedStimulusInfo::Clear(UFG::ReceivedStimulusInfo *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pProducer; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  p_m_pProducer = &this->m_LastTimeReceived.m_pProducer;
  this->m_LastTimeReceived.m_Time = -99999.0;
  if ( this->m_LastTimeReceived.m_pProducer.m_pPointer )
  {
    mPrev = p_m_pProducer->mPrev;
    mNext = this->m_LastTimeReceived.m_pProducer.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pProducer->mPrev = p_m_pProducer;
    this->m_LastTimeReceived.m_pProducer.mNext = &this->m_LastTimeReceived.m_pProducer;
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
    v4->mPrev = v4;
    v4->mNext = v4;
  }
  v4->m_pPointer = 0i64;
}

// File Line: 110
// RVA: 0x33B3F0
void __fastcall UFG::StimulusNotifyCallback::~StimulusNotifyCallback(UFG::StimulusNotifyCallback *this)
{
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *v1; // rdx
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *mPrev; // rcx
  UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback> *mNext; // rax

  this->vfptr = (UFG::StimulusNotifyCallbackVtbl *)&UFG::StimulusNotifyCallback::`vftable;
  v1 = &this->UFG::qNode<UFG::StimulusNotifyCallback,UFG::StimulusNotifyCallback>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 129
// RVA: 0x33F6F0
UFG::ComponentIDDesc *__fastcall UFG::StimulusReceiverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::StimulusReceiverComponent::_DescInit )
  {
    UFG::StimulusReceiverComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::StimulusReceiverComponent::_DescInit = 1;
    UFG::StimulusReceiverComponent::_TypeUID = UFG::StimulusReceiverComponent::_TypeIDesc.mChildBitMask | (UFG::StimulusReceiverComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::StimulusReceiverComponent::_StimulusReceiverComponentTypeUID = UFG::StimulusReceiverComponent::_TypeIDesc.mChildBitMask | (UFG::StimulusReceiverComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::StimulusReceiverComponent::_TypeIDesc;
}

