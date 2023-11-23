// File Line: 58
// RVA: 0x592B00
void __fastcall UFG::AmbientContextNode::AmbientContextNode(UFG::AmbientContextNode *this)
{
  UFG::qWiseSymbol *null; // rax

  this->m_context.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  null = UFG::qWiseSymbol::get_null();
  UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)this, null);
  *(_DWORD *)&this->m_lastIdx = 0xFFFF;
}

// File Line: 69
// RVA: 0x2797B0
void __fastcall UFG::AmbientContextNode::~AmbientContextNode(UFG::AmbientContextNode *this)
{
  UFG::qWiseSymbol *null; // rax

  null = UFG::qWiseSymbol::get_null();
  UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)this, null);
  *(_DWORD *)&this->m_lastIdx = 0xFFFF;
  _((AMD_HD3D *)this->m_context.mUID);
}

// File Line: 108
// RVA: 0x593C60
void __fastcall UFG::AmbientContextManager::~AmbientContextManager(UFG::AmbientContextManager *this)
{
  UFG::AmbientContextNode *p; // rcx
  unsigned __int16 *p_m_lastIdx; // rbx
  UFG::AmbientContextNode *v4; // rcx
  unsigned __int16 *v5; // rbx

  p = this->m_nodes.p;
  if ( p )
  {
    p_m_lastIdx = &p[-1].m_lastIdx;
    `eh vector destructor iterator(
      p,
      8ui64,
      *(_DWORD *)&p[-1].m_lastIdx,
      (void (__fastcall *)(void *))UFG::AmbientContextNode::~AmbientContextNode);
    operator delete[](p_m_lastIdx);
  }
  this->m_nodes.p = 0i64;
  *(_QWORD *)&this->m_nodes.size = 0i64;
  v4 = this->m_nodes.p;
  if ( v4 )
  {
    v5 = &v4[-1].m_lastIdx;
    `eh vector destructor iterator(
      v4,
      8ui64,
      *(_DWORD *)&v4[-1].m_lastIdx,
      (void (__fastcall *)(void *))UFG::AmbientContextNode::~AmbientContextNode);
    operator delete[](v5);
  }
  this->m_nodes.p = 0i64;
  *(_QWORD *)&this->m_nodes.size = 0i64;
}

// File Line: 128
// RVA: 0x593650
void __fastcall UFG::TaggedDialogueState::TaggedDialogueState(UFG::TaggedDialogueState *this)
{
  AMD_HD3D *mUID; // rcx
  AMD_HD3D *v3; // rcx

  this->vfptr = (UFG::TaggedDialogueStateVtbl *)&UFG::TaggedDialogueState::`vftable;
  mUID = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
  this->m_arg.mUID = (unsigned int)mUID;
  _(mUID);
  v3 = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
  this->m_bank.mUID = (unsigned int)v3;
  _(v3);
}

// File Line: 130
// RVA: 0x594A40
void __fastcall UFG::TaggedDialogueState::~TaggedDialogueState(UFG::TaggedDialogueState *this)
{
  this->vfptr = (UFG::TaggedDialogueStateVtbl *)&UFG::TaggedDialogueState::`vftable;
  _((AMD_HD3D *)this->m_bank.mUID);
  _((AMD_HD3D *)this->m_arg.mUID);
}

// File Line: 178
// RVA: 0x594BB0
void __fastcall UFG::NISCallback::operator delete(char *ptr, const char *name)
{
  *(_QWORD *)ptr = UFG::gAudioEventCallbackObjectPool.mFreeListHead;
  --UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated;
  UFG::gAudioEventCallbackObjectPool.mFreeListHead = ptr;
}

// File Line: 193
// RVA: 0x595A90
UFG::ComponentIDDesc *__fastcall UFG::ActorAudioComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::ActorAudioComponent::_DescInit )
  {
    v0 = UFG::HkAudioEntityComponent::AccessComponentDesc();
    ++UFG::HkAudioEntityComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HkAudioEntityComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::ActorAudioComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::ActorAudioComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::ActorAudioComponent::_TypeIDesc.mChildren = 0;
    UFG::ActorAudioComponent::_DescInit = 1;
    UFG::ActorAudioComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::ActorAudioComponent::_ActorAudioComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::ActorAudioComponent::_TypeIDesc;
}

// File Line: 210
// RVA: 0x59D870
UFG::qWiseSymbol *__fastcall UFG::ActorAudioComponent::GetVoiceId(
        UFG::ActorAudioComponent *this,
        UFG::qWiseSymbol *result)
{
  UFG::VoiceProfile *m_voiceProfile; // rax
  AMD_HD3D *mUID; // rcx

  m_voiceProfile = this->m_voiceProfile;
  if ( m_voiceProfile )
  {
    mUID = (AMD_HD3D *)m_voiceProfile->m_wwiseVoiceUid.mUID;
    result->mUID = (unsigned int)mUID;
  }
  else
  {
    mUID = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
    result->mUID = (unsigned int)mUID;
  }
  _(mUID);
  return result;
}

// File Line: 373
// RVA: 0x597570
bool __fastcall UFG::ActorAudioComponent::CanApplyEnvironment(
        UFG::ActorAudioComponent *this,
        UFG::qWiseSymbol *envType)
{
  return envType->mUID == UFG::WwiseEnvironment::sm_Speech.mUID || envType->mUID == UFG::WwiseEnvironment::sm_All.mUID;
}

