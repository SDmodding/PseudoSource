// File Line: 51
// RVA: 0x66C9B0
void __fastcall UFG::EngineModelInput::~EngineModelInput(UFG::EngineModelInput *this)
{
  UFG::EngineModelInput *v1; // rbx
  UFG::AudioEvent *v2; // rcx
  UFG::qNode<UFG::EngineModelInput,UFG::EngineModelInput> *v3; // rdx
  UFG::qNode<UFG::EngineModelInput,UFG::EngineModelInput> *v4; // rcx
  UFG::qNode<UFG::EngineModelInput,UFG::EngineModelInput> *v5; // rax

  v1 = this;
  this->vfptr = (UFG::EngineModelInputVtbl *)&UFG::EngineModelInput::`vftable';
  v2 = this->m_eventController.m_pEvent;
  if ( v2 )
    UFG::AudioEvent::OnControllerDestroy(v2);
  v3 = (UFG::qNode<UFG::EngineModelInput,UFG::EngineModelInput> *)&v1->mPrev;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v3->mPrev = v3;
  v3->mNext = v3;
}

// File Line: 119
// RVA: 0x66CA00
void __fastcall UFG::EngineModelOutput::~EngineModelOutput(UFG::EngineModelOutput *this)
{
  UFG::qNode<UFG::EngineModelOutput,UFG::EngineModelOutput> *v1; // rdx
  UFG::qNode<UFG::EngineModelOutput,UFG::EngineModelOutput> *v2; // rcx
  UFG::qNode<UFG::EngineModelOutput,UFG::EngineModelOutput> *v3; // rax

  this->vfptr = (UFG::EngineModelOutputVtbl *)&UFG::EngineModelOutput::`vftable';
  v1 = (UFG::qNode<UFG::EngineModelOutput,UFG::EngineModelOutput> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 282
// RVA: 0x66C040
void __fastcall UFG::Base_EngineState::~Base_EngineState(UFG::Base_EngineState *this)
{
  this->vfptr = (UFG::Base_EngineStateVtbl *)&UFG::Base_EngineState::`vftable';
}

// File Line: 496
// RVA: 0x66DB90
void __fastcall UFG::AmbientConversationConfigurator::Action::operator delete(void *ptr, const char *name)
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

