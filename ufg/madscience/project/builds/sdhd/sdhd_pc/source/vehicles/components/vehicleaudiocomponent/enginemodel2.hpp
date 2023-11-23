// File Line: 51
// RVA: 0x66C9B0
void __fastcall UFG::EngineModelInput::~EngineModelInput(UFG::EngineModelInput *this)
{
  UFG::AudioEvent *m_pEvent; // rcx
  UFG::qNode<UFG::EngineModelInput,UFG::EngineModelInput> *mPrev; // rcx
  UFG::qNode<UFG::EngineModelInput,UFG::EngineModelInput> *mNext; // rax

  this->vfptr = (UFG::EngineModelInputVtbl *)&UFG::EngineModelInput::`vftable;
  m_pEvent = this->m_eventController.m_pEvent;
  if ( m_pEvent )
    UFG::AudioEvent::OnControllerDestroy(m_pEvent);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::EngineModelInput,UFG::EngineModelInput>;
  this->mNext = &this->UFG::qNode<UFG::EngineModelInput,UFG::EngineModelInput>;
}

// File Line: 119
// RVA: 0x66CA00
void __fastcall UFG::EngineModelOutput::~EngineModelOutput(UFG::EngineModelOutput *this)
{
  UFG::qNode<UFG::EngineModelOutput,UFG::EngineModelOutput> *v1; // rdx
  UFG::qNode<UFG::EngineModelOutput,UFG::EngineModelOutput> *mPrev; // rcx
  UFG::qNode<UFG::EngineModelOutput,UFG::EngineModelOutput> *mNext; // rax

  this->vfptr = (UFG::EngineModelOutputVtbl *)&UFG::EngineModelOutput::`vftable;
  v1 = &this->UFG::qNode<UFG::EngineModelOutput,UFG::EngineModelOutput>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 282
// RVA: 0x66C040
void __fastcall UFG::Base_EngineState::~Base_EngineState(UFG::Base_EngineState *this)
{
  this->vfptr = (UFG::Base_EngineStateVtbl *)&UFG::Base_EngineState::`vftable;
}

// File Line: 496
// RVA: 0x66DB90
void __fastcall UFG::AmbientConversationConfigurator::Action::operator delete(char *ptr, const char *name)
{
  UFG::qMemoryPool::Free(&g_AudioComponentPool, ptr);
}

// File Line: 558
// RVA: 0x67A330
float __fastcall UFG::Drifting_EngineState::GetDefaultLoad(PoseNode *this, float futureTimeDelta)
{
  return FLOAT_N1_0;
}

// File Line: 644
// RVA: 0x67A340
float __fastcall UFG::Wheelie_EngineState::GetDefaultLoad(CAkSrcFileVorbis *this, AkAudioFormat *in_rFormat)
{
  return *(float *)&FLOAT_1_0;
}

