// File Line: 58
// RVA: 0x592B00
void __fastcall UFG::AmbientContextNode::AmbientContextNode(UFG::AmbientContextNode *this)
{
  UFG::qWiseSymbol *v1; // rbx
  UFG::qWiseSymbol *v2; // rax

  v1 = (UFG::qWiseSymbol *)this;
  this->m_context.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  v2 = UFG::qWiseSymbol::get_null();
  UFG::qWiseSymbol::operator=(v1, v2);
  v1[1].mUID = 0xFFFF;
}

// File Line: 69
// RVA: 0x2797B0
void __fastcall UFG::AmbientContextNode::~AmbientContextNode(UFG::AmbientContextNode *this)
{
  UFG::qWiseSymbol *v1; // rbx
  UFG::qWiseSymbol *v2; // rax

  v1 = (UFG::qWiseSymbol *)this;
  v2 = UFG::qWiseSymbol::get_null();
  UFG::qWiseSymbol::operator=(v1, v2);
  v1[1].mUID = 0xFFFF;
  _((AMD_HD3D *)v1->mUID);
}

// File Line: 108
// RVA: 0x593C60
void __fastcall UFG::AmbientContextManager::~AmbientContextManager(UFG::AmbientContextManager *this)
{
  UFG::AmbientContextManager *v1; // rdi
  UFG::AmbientContextNode *v2; // rcx
  unsigned __int16 *v3; // rbx
  UFG::AmbientContextNode *v4; // rcx
  unsigned __int16 *v5; // rbx

  v1 = this;
  v2 = this->m_nodes.p;
  if ( v2 )
  {
    v3 = &v2[-1].m_lastIdx;
    `eh vector destructor iterator'(
      v2,
      8ui64,
      *(_DWORD *)&v2[-1].m_lastIdx,
      (void (__fastcall *)(void *))UFG::AmbientContextNode::~AmbientContextNode);
    operator delete[](v3);
  }
  v1->m_nodes.p = 0i64;
  *(_QWORD *)&v1->m_nodes.size = 0i64;
  v4 = v1->m_nodes.p;
  if ( v4 )
  {
    v5 = &v4[-1].m_lastIdx;
    `eh vector destructor iterator'(
      v4,
      8ui64,
      *(_DWORD *)&v4[-1].m_lastIdx,
      (void (__fastcall *)(void *))UFG::AmbientContextNode::~AmbientContextNode);
    operator delete[](v5);
  }
  v1->m_nodes.p = 0i64;
  *(_QWORD *)&v1->m_nodes.size = 0i64;
}

// File Line: 128
// RVA: 0x593650
void __fastcall UFG::TaggedDialogueState::TaggedDialogueState(UFG::TaggedDialogueState *this)
{
  UFG::TaggedDialogueState *v1; // rbx
  AMD_HD3D *v2; // rcx
  AMD_HD3D *v3; // rcx

  v1 = this;
  this->vfptr = (UFG::TaggedDialogueStateVtbl *)&UFG::TaggedDialogueState::`vftable';
  v2 = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
  v1->m_arg.mUID = (unsigned int)v2;
  _(v2);
  v3 = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
  v1->m_bank.mUID = (unsigned int)v3;
  _(v3);
}

// File Line: 130
// RVA: 0x594A40
void __fastcall UFG::TaggedDialogueState::~TaggedDialogueState(UFG::TaggedDialogueState *this)
{
  UFG::TaggedDialogueState *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::TaggedDialogueStateVtbl *)&UFG::TaggedDialogueState::`vftable';
  _((AMD_HD3D *)this->m_bank.mUID);
  _((AMD_HD3D *)v1->m_arg.mUID);
}

// File Line: 178
// RVA: 0x594BB0
void __fastcall UFG::NISCallback::operator delete(void *ptr, const char *name)
{
  *(_QWORD *)ptr = UFG::gAudioEventCallbackObjectPool.mFreeListHead;
  --UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated;
  UFG::gAudioEventCallbackObjectPool.mFreeListHead = (char *)ptr;
}

// File Line: 193
// RVA: 0x595A90
UFG::ComponentIDDesc *__fastcall UFG::ActorAudioComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::ActorAudioComponent::_DescInit )
  {
    v0 = UFG::HkAudioEntityComponent::AccessComponentDesc();
    ++UFG::HkAudioEntityComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HkAudioEntityComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::ActorAudioComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::ActorAudioComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::ActorAudioComponent::_TypeIDesc.mChildren = 0;
    UFG::ActorAudioComponent::_DescInit = 1;
    UFG::ActorAudioComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::ActorAudioComponent::_ActorAudioComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::ActorAudioComponent::_TypeIDesc;
}

// File Line: 210
// RVA: 0x59D870
UFG::qWiseSymbol *__fastcall UFG::ActorAudioComponent::GetVoiceId(UFG::ActorAudioComponent *this, UFG::qWiseSymbol *result)
{
  UFG::qWiseSymbol *v2; // rbx
  UFG::VoiceProfile *v3; // rax
  AMD_HD3D *v4; // rcx

  v2 = result;
  v3 = this->m_voiceProfile;
  if ( v3 )
  {
    v4 = (AMD_HD3D *)v3->m_wwiseVoiceUid.mUID;
    result->mUID = (unsigned int)v4;
  }
  else
  {
    v4 = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
    v2->mUID = (unsigned int)v4;
  }
  _(v4);
  return v2;
}

// File Line: 373
// RVA: 0x597570
bool __fastcall UFG::ActorAudioComponent::CanApplyEnvironment(UFG::ActorAudioComponent *this, UFG::qWiseSymbol *envType)
{
  return envType->mUID == UFG::WwiseEnvironment::sm_Speech.mUID || envType->mUID == UFG::WwiseEnvironment::sm_All.mUID;
}

