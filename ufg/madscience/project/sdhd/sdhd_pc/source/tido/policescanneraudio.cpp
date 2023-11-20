// File Line: 57
// RVA: 0x155CF70
__int64 UFG::_dynamic_initializer_for__squelch__()
{
  squelch.mUID = UFG::qWiseSymbolUIDFromString("squelch", 0x811C9DC5);
  _((AMD_HD3D *)squelch.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__squelch__);
}

// File Line: 58
// RVA: 0x1559C40
__int64 UFG::_dynamic_initializer_for__external_source__()
{
  external_source.mUID = UFG::qWiseSymbolUIDFromString("external_source", 0x811C9DC5);
  _((AMD_HD3D *)external_source.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__external_source__);
}

// File Line: 59
// RVA: 0x1559F80
__int64 UFG::_dynamic_initializer_for__heat_voice__()
{
  heat_voice.mUID = UFG::qWiseSymbolUIDFromString("heat_voice", 0x811C9DC5);
  _((AMD_HD3D *)heat_voice.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__heat_voice__);
}

// File Line: 88
// RVA: 0x1554B30
__int64 dynamic_initializer_for__UFG::PoliceScannerAudio::sm_Instance__()
{
  UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)&UFG::PoliceScannerAudio::sm_Instance.vfptr);
  UFG::PoliceScannerAudio::sm_Instance.vfptr = (UFG::AudioEntityVtbl *)&UFG::PoliceScannerAudio::`vftable';
  unk_14242F240 = 0;
  unk_14242F248 = 0i64;
  UFG::qBaseTreeRB::qBaseTreeRB(&stru_14242F250);
  qword_14242F298 = 0i64;
  return atexit(dynamic_atexit_destructor_for__UFG::PoliceScannerAudio::sm_Instance__);
}

// File Line: 90
// RVA: 0x155D100
__int64 UFG::_dynamic_initializer_for__strBlahBlahTest__()
{
  UFG::qString::qString(&strBlahBlahTest);
  return atexit(UFG::_dynamic_atexit_destructor_for__strBlahBlahTest__);
}

// File Line: 100
// RVA: 0x594780
void __fastcall UFG::PoliceScannerAudio::~PoliceScannerAudio(UFG::PoliceScannerAudio *this)
{
  UFG::PoliceScannerAudio *v1; // rdi
  UFG::AudioEvent *v2; // rcx

  v1 = this;
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::PoliceScannerAudio::`vftable';
  v2 = this->m_Controller.m_pEvent;
  if ( v2 )
    UFG::AudioEvent::OnControllerDestroy(v2);
  UFG::qTreeRB<UFG::SpeechScenario,UFG::SpeechScenario,1>::DeleteAll(&v1->m_Scenarios);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->m_Scenarios);
  UFG::AudioEntity::~AudioEntity((UFG::AudioEntity *)&v1->vfptr);
}

// File Line: 104
// RVA: 0x596F60
void __fastcall UFG::PoliceScannerAudio::AttachToAudioEntity(UFG::PoliceScannerAudio *this, UFG::AudioEntity *pEntity)
{
  this->m_pOwnerEntity = pEntity;
}

// File Line: 110
// RVA: 0x59B0D0
void __fastcall UFG::PoliceScannerAudio::DetachFromAudioEntity(UFG::PoliceScannerAudio *this, UFG::AudioEntity *pEntity)
{
  this->m_pOwnerEntity = 0i64;
}

// File Line: 116
// RVA: 0x5A0650
bool __fastcall UFG::PoliceScannerAudio::IsOwnedBy(UFG::PoliceScannerAudio *this, UFG::AudioEntity *pEntity)
{
  return this->m_pOwnerEntity == pEntity;
}

// File Line: 126
// RVA: 0x59B5F0
void __fastcall UFG::PoliceScannerAudio::Enable(UFG::PoliceScannerAudio *this, bool isEnabled)
{
  bool v2; // di
  UFG::PoliceScannerAudio *v3; // rbx
  bool v4; // al
  UFG::AudioEvent *v5; // rcx

  v2 = isEnabled;
  v3 = this;
  if ( isEnabled && !this->m_enabled )
    UFG::PoliceScannerAudio::PlayClick(this);
  v4 = v3->m_enabled;
  v3->m_enabled = v2;
  if ( !v2 && v4 )
  {
    v5 = v3->m_Controller.m_pEvent;
    if ( v5 )
    {
      UFG::AudioEvent::StopAndForget(v5, 0);
      UFG::PoliceScannerAudio::PlayClick(v3);
    }
  }
}

// File Line: 164
// RVA: 0x5A1B50
void __fastcall UFG::PoliceScannerAudio::LoadScenarios(UFG::PoliceScannerAudio *this)
{
  UFG::PoliceScannerAudio *v1; // rsi
  UFG::allocator::free_link *v2; // rax
  UFG::SpeechScenario *v3; // rdi
  UFG::qBaseTreeRB *v4; // rsi
  UFG::allocator::free_link *v5; // rax
  UFG::SpeechScenario *v6; // rdi
  UFG::allocator::free_link *v7; // rax
  UFG::SpeechScenario *v8; // rdi
  UFG::allocator::free_link *v9; // rax
  UFG::SpeechScenario *v10; // rdi
  UFG::allocator::free_link *v11; // rax
  UFG::SpeechScenario *v12; // rdi
  UFG::allocator::free_link *v13; // rax
  UFG::SpeechScenario *v14; // rdi
  UFG::allocator::free_link *v15; // rax
  UFG::SpeechScenario *v16; // rdi
  UFG::allocator::free_link *v17; // rax
  UFG::SpeechScenario *v18; // rdi
  UFG::allocator::free_link *v19; // rax
  UFG::SpeechScenario *v20; // rdi

  v1 = this;
  v2 = UFG::qMalloc(0xB0ui64, "SpeechScenario", 0i64);
  v3 = (UFG::SpeechScenario *)v2;
  if ( v2 )
  {
    v2->mNext = 0i64;
    v2[1].mNext = 0i64;
    v2[2].mNext = 0i64;
    v2[21].mNext = 0i64;
    v2[20].mNext = 0i64;
    UFG::qSPrintf((char *)&v2[4], 128, "Begin_Pursuit");
    v3->mNode.mUID = UFG::qStringHashUpper32("Begin_Pursuit", 0xFFFFFFFF);
  }
  else
  {
    v3 = 0i64;
  }
  UFG::PoliceScannerAudio::LoadScenarios_::_2_::local::AddLine(v3, 0, UFG::police_radio_start_chase_string, 0, 0);
  UFG::PoliceScannerAudio::LoadScenarios_::_2_::local::AddLine(v3, 0, UFG::police_radio_response_string, 0x1F4u, 0x3E8u);
  v4 = &v1->m_Scenarios.mTree;
  UFG::qBaseTreeRB::Add(v4, &v3->mNode);
  v5 = UFG::qMalloc(0xB0ui64, "SpeechScenario", 0i64);
  v6 = (UFG::SpeechScenario *)v5;
  if ( v5 )
  {
    v5->mNext = 0i64;
    v5[1].mNext = 0i64;
    v5[2].mNext = 0i64;
    v5[21].mNext = 0i64;
    v5[20].mNext = 0i64;
    UFG::qSPrintf((char *)&v5[4], 128, "End_Pursuit");
    v6->mNode.mUID = UFG::qStringHashUpper32("End_Pursuit", 0xFFFFFFFF);
  }
  else
  {
    v6 = 0i64;
  }
  UFG::PoliceScannerAudio::LoadScenarios_::_2_::local::AddLine(v6, 0, UFG::police_radio_cooldown_string, 0, 0);
  UFG::PoliceScannerAudio::LoadScenarios_::_2_::local::AddLine(
    v6,
    0,
    UFG::police_radio_end_chase_string,
    0x1F4u,
    0x3E8u);
  UFG::qBaseTreeRB::Add(v4, &v6->mNode);
  v7 = UFG::qMalloc(0xB0ui64, "SpeechScenario", 0i64);
  v8 = (UFG::SpeechScenario *)v7;
  if ( v7 )
  {
    v7->mNext = 0i64;
    v7[1].mNext = 0i64;
    v7[2].mNext = 0i64;
    v7[21].mNext = 0i64;
    v7[20].mNext = 0i64;
    UFG::qSPrintf((char *)&v7[4], 128, "Chase");
    v8->mNode.mUID = UFG::qStringHashUpper32("Chase", 0xFFFFFFFF);
  }
  else
  {
    v8 = 0i64;
  }
  UFG::PoliceScannerAudio::LoadScenarios_::_2_::local::AddLine(v8, 0, UFG::police_radio_chase_string, 0, 0);
  UFG::qBaseTreeRB::Add(v4, &v8->mNode);
  v9 = UFG::qMalloc(0xB0ui64, "SpeechScenario", 0i64);
  v10 = (UFG::SpeechScenario *)v9;
  if ( v9 )
  {
    v9->mNext = 0i64;
    v9[1].mNext = 0i64;
    v9[2].mNext = 0i64;
    v9[21].mNext = 0i64;
    v9[20].mNext = 0i64;
    UFG::qSPrintf((char *)&v9[4], 128, "Ambient_Chatter");
    v10->mNode.mUID = UFG::qStringHashUpper32("Ambient_Chatter", 0xFFFFFFFF);
  }
  else
  {
    v10 = 0i64;
  }
  UFG::PoliceScannerAudio::LoadScenarios_::_2_::local::AddLine(v10, 0, UFG::police_radio_chatter_string, 0, 0);
  UFG::PoliceScannerAudio::LoadScenarios_::_2_::local::AddLine(
    v10,
    0,
    UFG::police_radio_response_string,
    0x3E8u,
    0x7D0u);
  UFG::qBaseTreeRB::Add(v4, &v10->mNode);
  v11 = UFG::qMalloc(0xB0ui64, "SpeechScenario", 0i64);
  v12 = (UFG::SpeechScenario *)v11;
  if ( v11 )
  {
    v11->mNext = 0i64;
    v11[1].mNext = 0i64;
    v11[2].mNext = 0i64;
    v11[21].mNext = 0i64;
    v11[20].mNext = 0i64;
    UFG::qSPrintf((char *)&v11[4], 128, "HeatLevel_One");
    v12->mNode.mUID = UFG::qStringHashUpper32("HeatLevel_One", 0xFFFFFFFF);
  }
  else
  {
    v12 = 0i64;
  }
  UFG::PoliceScannerAudio::LoadScenarios_::_2_::local::AddLine(v12, 0, UFG::police_radio_chase_string, 0, 0);
  UFG::PoliceScannerAudio::LoadScenarios_::_2_::local::AddLine(
    v12,
    0,
    UFG::police_radio_response_string,
    0x3E8u,
    0x7D0u);
  UFG::qBaseTreeRB::Add(v4, &v12->mNode);
  v13 = UFG::qMalloc(0xB0ui64, "SpeechScenario", 0i64);
  v14 = (UFG::SpeechScenario *)v13;
  if ( v13 )
  {
    v13->mNext = 0i64;
    v13[1].mNext = 0i64;
    v13[2].mNext = 0i64;
    v13[21].mNext = 0i64;
    v13[20].mNext = 0i64;
    UFG::qSPrintf((char *)&v13[4], 128, "HeatLevel_Two");
    v14->mNode.mUID = UFG::qStringHashUpper32("HeatLevel_Two", 0xFFFFFFFF);
  }
  else
  {
    v14 = 0i64;
  }
  UFG::PoliceScannerAudio::LoadScenarios_::_2_::local::AddLine(v14, 0, UFG::police_radio_chase_string, 0, 0);
  UFG::PoliceScannerAudio::LoadScenarios_::_2_::local::AddLine(
    v14,
    0,
    UFG::police_radio_response_string,
    0x3E8u,
    0x7D0u);
  UFG::qBaseTreeRB::Add(v4, &v14->mNode);
  v15 = UFG::qMalloc(0xB0ui64, "SpeechScenario", 0i64);
  v16 = (UFG::SpeechScenario *)v15;
  if ( v15 )
  {
    v15->mNext = 0i64;
    v15[1].mNext = 0i64;
    v15[2].mNext = 0i64;
    v15[21].mNext = 0i64;
    v15[20].mNext = 0i64;
    UFG::qSPrintf((char *)&v15[4], 128, "HeatLevel_Three");
    v16->mNode.mUID = UFG::qStringHashUpper32("HeatLevel_Three", 0xFFFFFFFF);
  }
  else
  {
    v16 = 0i64;
  }
  UFG::PoliceScannerAudio::LoadScenarios_::_2_::local::AddLine(
    v16,
    ePoliceVoiceType_Heat,
    UFG::police_radio_heat_3_string,
    0,
    0);
  UFG::qBaseTreeRB::Add(v4, &v16->mNode);
  v17 = UFG::qMalloc(0xB0ui64, "SpeechScenario", 0i64);
  v18 = (UFG::SpeechScenario *)v17;
  if ( v17 )
  {
    v17->mNext = 0i64;
    v17[1].mNext = 0i64;
    v17[2].mNext = 0i64;
    v17[21].mNext = 0i64;
    v17[20].mNext = 0i64;
    UFG::qSPrintf((char *)&v17[4], 128, "HeatLevel_Four");
    v18->mNode.mUID = UFG::qStringHashUpper32("HeatLevel_Four", 0xFFFFFFFF);
  }
  else
  {
    v18 = 0i64;
  }
  UFG::PoliceScannerAudio::LoadScenarios_::_2_::local::AddLine(
    v18,
    ePoliceVoiceType_Heat,
    UFG::police_radio_heat_4_string,
    0,
    0);
  UFG::qBaseTreeRB::Add(v4, &v18->mNode);
  v19 = UFG::qMalloc(0xB0ui64, "SpeechScenario", 0i64);
  v20 = (UFG::SpeechScenario *)v19;
  if ( v19 )
  {
    v19->mNext = 0i64;
    v19[1].mNext = 0i64;
    v19[2].mNext = 0i64;
    v19[21].mNext = 0i64;
    v19[20].mNext = 0i64;
    UFG::qSPrintf((char *)&v19[4], 128, "HeatLevel_Five");
    v20->mNode.mUID = UFG::qStringHashUpper32("HeatLevel_Five", 0xFFFFFFFF);
  }
  else
  {
    v20 = 0i64;
  }
  UFG::PoliceScannerAudio::LoadScenarios_::_2_::local::AddLine(
    v20,
    ePoliceVoiceType_Heat,
    UFG::police_radio_heat_5_string,
    0,
    0);
  UFG::qBaseTreeRB::Add(v4, &v20->mNode);
}

// File Line: 168
// RVA: 0x596320
void __fastcall UFG::PoliceScannerAudio::LoadScenarios_::_2_::local::AddLine(UFG::SpeechScenario *pScenario, UFG::PoliceVoiceType voiceType, const char *context, unsigned int minDelay, unsigned int maxDelay)
{
  UFG::qArray<UFG::SpeechObject,0> *v5; // rsi
  UFG::PoliceVoiceType v6; // er12
  unsigned int v7; // er14
  __int64 v8; // rbp
  unsigned int v9; // edx
  const char *v10; // r15
  unsigned int v11; // edi
  unsigned int v12; // ebx
  unsigned int v13; // edx
  UFG::qStaticWiseSymbol *v14; // rcx
  unsigned int v15; // eax
  __int64 v16; // rbp
  unsigned int v17; // edx
  unsigned int v18; // edi
  unsigned int v19; // edx
  signed __int64 v20; // rcx
  unsigned int v21; // eax
  __int64 v22; // rbp
  unsigned int v23; // eax
  unsigned int v24; // edi
  UFG::qStaticWiseSymbol *v25; // rcx
  unsigned int v26; // eax

  v5 = &pScenario->m_ObjectArray;
  v6 = voiceType;
  v7 = minDelay;
  v8 = pScenario->m_ObjectArray.size;
  v9 = pScenario->m_ObjectArray.capacity;
  v10 = context;
  v11 = v8 + 1;
  v12 = 1;
  if ( (signed int)v8 + 1 > v9 )
  {
    if ( v9 )
      v13 = 2 * v9;
    else
      v13 = 1;
    for ( ; v13 < v11; v13 *= 2 )
      ;
    if ( v13 - v11 > 0x10000 )
      v13 = v8 + 65537;
    UFG::qArray<UFG::SpeechObject,0>::Reallocate(&pScenario->m_ObjectArray, v13, "TiDoHK");
  }
  v5->size = v11;
  v14 = (UFG::qStaticWiseSymbol *)&v5->p[v8];
  v14->mUID = play_police_scanner_22.mUID;
  v15 = squelch.mUID;
  v14[6].mUID = v7;
  v14[1].mUID = v15;
  v14[7].mUID = maxDelay;
  v16 = v5->size;
  v17 = v5->capacity;
  v18 = v16 + 1;
  if ( (signed int)v16 + 1 > v17 )
  {
    if ( v17 )
      v19 = 2 * v17;
    else
      v19 = 1;
    for ( ; v19 < v18; v19 *= 2 )
      ;
    if ( v19 - v18 > 0x10000 )
      v19 = v16 + 65537;
    UFG::qArray<UFG::SpeechObject,0>::Reallocate(v5, v19, "TiDoHK");
  }
  v5->size = v18;
  v20 = (signed __int64)&v5->p[v16];
  *(UFG::qStaticWiseSymbol *)v20 = play_police_scanner_22;
  v21 = external_source.mUID;
  *(_DWORD *)(v20 + 8) = v6;
  *(_QWORD *)(v20 + 16) = v10;
  *(_DWORD *)(v20 + 24) = 70;
  *(_DWORD *)(v20 + 28) = 200;
  *(_DWORD *)(v20 + 4) = v21;
  v22 = v5->size;
  v23 = v5->capacity;
  v24 = v22 + 1;
  if ( (signed int)v22 + 1 > v23 )
  {
    if ( v23 )
      v12 = 2 * v23;
    for ( ; v12 < v24; v12 *= 2 )
      ;
    if ( v12 - v24 > 0x10000 )
      v12 = v22 + 65537;
    UFG::qArray<UFG::SpeechObject,0>::Reallocate(v5, v12, "TiDoHK");
  }
  v5->size = v24;
  v25 = (UFG::qStaticWiseSymbol *)&v5->p[v22];
  v25->mUID = play_police_scanner_22.mUID;
  v26 = squelch.mUID;
  v25[6].mUID = 70;
  v25[1].mUID = v26;
  v25[7].mUID = 200;
}

// File Line: 283
// RVA: 0x5A5010
void __fastcall UFG::PoliceScannerAudio::PlayClick(UFG::PoliceScannerAudio *this)
{
  UFG::PoliceScannerAudio *v1; // rbx
  UFG::TiDo *v2; // rax
  UFG::Audio3DListener *v3; // rax
  unsigned int v4; // eax

  v1 = this;
  v2 = UFG::TiDo::GetInstance();
  v3 = UFG::TiDo::GetListener(v2, 0);
  if ( (float)((float)((float)((float)(v3->m_matrix.v3.y - v1->m_WorldMatrix.v3.y)
                             * (float)(v3->m_matrix.v3.y - v1->m_WorldMatrix.v3.y))
                     + (float)((float)(v3->m_matrix.v3.x - v1->m_WorldMatrix.v3.x)
                             * (float)(v3->m_matrix.v3.x - v1->m_WorldMatrix.v3.x)))
             + (float)((float)(v3->m_matrix.v3.z - v1->m_WorldMatrix.v3.z)
                     * (float)(v3->m_matrix.v3.z - v1->m_WorldMatrix.v3.z))) <= 100.0 )
  {
    if ( _S39_0 & 1 )
    {
      v4 = uiClickId;
    }
    else
    {
      _S39_0 |= 1u;
      v4 = UFG::TiDo::CalcWwiseUid("play_ui_click");
      uiClickId = v4;
    }
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v1->vfptr, v4, 0i64, 0, 0i64);
  }
}

// File Line: 297
// RVA: 0x59CC60
const char *__fastcall UFG::PoliceScannerAudio::GenerateRandomVoice(UFG::PoliceScannerAudio *this)
{
  int v1; // eax
  UFG::PoliceScannerAudio *v2; // rbx
  const char *v3; // rdx
  int v4; // ecx
  const char *result; // rax

  v1 = this->m_previousPoliceVoices[1];
  v2 = this;
  v3 = 0i64;
  while ( v1 == v2->m_previousPoliceVoices[0] || v1 == v2->m_previousPoliceVoices[1] )
  {
    v1 = UFG::qRandom(5, &UFG::qDefaultSeed);
    v3 = UFG::gPoliceVoices[v1];
  }
  v4 = v2->m_previousPoliceVoices[1];
  v2->m_previousPoliceVoices[1] = v1;
  result = v3;
  v2->m_previousPoliceVoices[0] = v4;
  return result;
}

// File Line: 315
// RVA: 0x59CBF0
const char *__fastcall UFG::PoliceScannerAudio::GenerateRandomHeatVoice(UFG::PoliceScannerAudio *this)
{
  int v1; // eax
  UFG::PoliceScannerAudio *v2; // rbx
  const char *v3; // rdx
  int v4; // ecx
  const char *result; // rax

  v1 = this->m_previousHeatVoices[1];
  v2 = this;
  v3 = 0i64;
  while ( v1 == v2->m_previousHeatVoices[0] || v1 == v2->m_previousHeatVoices[1] )
  {
    v1 = UFG::qRandom(3, &UFG::qDefaultSeed);
    v3 = UFG::gHeatVoices[v1];
  }
  v4 = v2->m_previousHeatVoices[1];
  v2->m_previousHeatVoices[1] = v1;
  result = v3;
  v2->m_previousHeatVoices[0] = v4;
  return result;
}

// File Line: 333
// RVA: 0x5A7030
char __fastcall UFG::PoliceScannerAudio::PlayScenario(UFG::PoliceScannerAudio *this, const char *pszScenarioName)
{
  const char *v2; // rdi
  UFG::PoliceScannerAudio *v3; // rsi
  UFG::TiDo *v4; // rax
  UFG::Audio3DListener *v5; // rax
  UFG::AudioEvent **v7; // r12
  char v8; // bl
  unsigned int v9; // eax
  UFG::qBaseTreeRB *v10; // rax
  UFG::qBaseTreeRB *v11; // r15
  UFG::AudioEventCallbackObject *v12; // rax
  unsigned int v13; // ebp
  signed __int64 v14; // rbx
  unsigned int v15; // ecx
  unsigned int v16; // er13
  const char *v17; // rax
  unsigned int v18; // eax
  UFG::allocator::free_link *v19; // rax
  __int64 v20; // rax
  __int64 v21; // r14
  __int64 v22; // rcx
  __int64 v23; // rbx
  UFG::qString v24; // [rsp+40h] [rbp-68h]
  UFG::AudioEventCallbackObject *final_hash; // [rsp+B0h] [rbp+8h]
  unsigned int args; // [rsp+C0h] [rbp+18h]
  unsigned int nodeId; // [rsp+C8h] [rbp+20h]

  v2 = pszScenarioName;
  v3 = this;
  if ( !this->m_enabled )
    return 0;
  v4 = UFG::TiDo::GetInstance();
  v5 = UFG::TiDo::GetListener(v4, 0);
  if ( (float)((float)((float)((float)(v5->m_matrix.v3.x - v3->m_WorldMatrix.v3.x)
                             * (float)(v5->m_matrix.v3.x - v3->m_WorldMatrix.v3.x))
                     + (float)((float)(v5->m_matrix.v3.y - v3->m_WorldMatrix.v3.y)
                             * (float)(v5->m_matrix.v3.y - v3->m_WorldMatrix.v3.y)))
             + (float)((float)(v5->m_matrix.v3.z - v3->m_WorldMatrix.v3.z)
                     * (float)(v5->m_matrix.v3.z - v3->m_WorldMatrix.v3.z))) > 10000.0 )
    return 1;
  v7 = &v3->m_Controller.m_pEvent;
  if ( v3->m_Controller.m_pEvent )
    return 0;
  v8 = 0;
  v9 = UFG::qStringHashUpper32(v2, 0xFFFFFFFF);
  if ( !v9 )
    return v8;
  v10 = UFG::qBaseTreeRB::Get(&v3->m_Scenarios.mTree, v9);
  v11 = v10;
  if ( !v10 )
    return v8;
  if ( !LODWORD(v10[2].mRoot.mChild[1]) )
    return v8;
  UFG::AudioEntity::CreateDialogEvent(
    (UFG::AudioEntity *)&v3->vfptr,
    (UFG::AudioEventController *)&v3->m_Controller.m_pEvent,
    0i64,
    0i64);
  if ( !*v7 )
    return v8;
  v12 = (UFG::AudioEventCallbackObject *)UFG::AACSubtitleCallback::operator new(
                                           0x10ui64,
                                           "PoliceScannerAudio.PoliceScannerCallback");
  final_hash = v12;
  if ( v12 )
  {
    v12->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable';
    v12->m_next = 0i64;
    v12->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::PoliceScannerCallback::`vftable';
  }
  else
  {
    v12 = 0i64;
  }
  if ( *v7 )
    UFG::AudioEvent::AddCallback(*v7, v12);
  v13 = 0;
  if ( !LODWORD(v11[2].mRoot.mChild[1]) )
    return UFG::AudioEventController::Play((UFG::AudioEventController *)&v3->m_Controller.m_pEvent, 0);
  while ( 1 )
  {
    v14 = *(_QWORD *)&v11[2].mRoot.mUID + 32i64 * v13;
    args = *(_DWORD *)(v14 + 4);
    v15 = 0;
    if ( *(_DWORD *)v14 == play_police_scanner_22.mUID )
    {
      v15 = play_police_scanner_inside_22.mUID;
      if ( (UFG::RadioFullyControlled *)v3->m_pOwnerEntity == UFG::RadioFullyControlled::sm_playerRadio )
        v15 = play_police_scanner_22.mUID;
    }
    nodeId = UFG::TiDo::ResolveDialogueEvent(v15, &args, 1u);
    v16 = *(_DWORD *)(v14 + 24)
        + (unsigned __int64)UFG::qRandom(*(_DWORD *)(v14 + 28) - *(_DWORD *)(v14 + 24), &UFG::qDefaultSeed);
    if ( *(_DWORD *)(v14 + 4) != external_source.mUID )
      goto LABEL_28;
    v17 = 0i64;
    if ( !*(_DWORD *)(v14 + 8) )
      v17 = UFG::PoliceScannerAudio::GenerateRandomVoice(v3);
    if ( *(_DWORD *)(v14 + 8) == 1 )
      v17 = UFG::PoliceScannerAudio::GenerateRandomHeatVoice(v3);
    UFG::qString::qString(&v24, "%s.%s.%s.", v17, *(_QWORD *)(v14 + 16), "001");
    v18 = UFG::TiDo::CalcWwiseUid(v24.mData);
    LODWORD(final_hash) = 0;
    if ( (unsigned int)UFG::ExternalSourceUtil::GetRandomVariation(v18, (unsigned int *)&final_hash, -1) == -1 )
      break;
    v19 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x20ui64, "ExternalSourceInfo.QueueSpeech", 0i64, 1u);
    if ( v19 )
    {
      UFG::AudioEventExternalSourceInfo::AudioEventExternalSourceInfo((UFG::AudioEventExternalSourceInfo *)v19, 1u);
      v21 = v20;
    }
    else
    {
      v21 = 0i64;
    }
    (*(UFG::qStaticWiseSymbol **)(v21 + 24))->mUID = slot_1_22.mUID;
    v22 = *(_QWORD *)(v21 + 24);
    *(_DWORD *)(v22 + 8) = (_DWORD)final_hash;
    v23 = *(_QWORD *)(v21 + 24);
    *(_DWORD *)(v23 + 4) = Scaleform::Render::DICommand_ApplyFilter::GetType((CAkSwitchCntr *)v22);
    UFG::AudioDialogEvent::EnqueueExternal(
      (UFG::AudioDialogEvent *)*v7,
      nodeId,
      (UFG::AudioEventExternalSourceInfo *)v21,
      v16);
    UFG::qString::~qString(&v24);
LABEL_28:
    if ( ++v13 >= LODWORD(v11[2].mRoot.mChild[1]) )
      return UFG::AudioEventController::Play((UFG::AudioEventController *)&v3->m_Controller.m_pEvent, 0);
  }
  if ( *v7 )
    UFG::AudioEvent::StopAndForget(*v7, 0);
  UFG::qString::~qString(&v24);
  return 0;
}

// File Line: 446
// RVA: 0x5A4380
void __fastcall UFG::PoliceScannerAudio::OnHeatLevelIncrease(UFG::PoliceScannerAudio *this, unsigned int newHeatLevel)
{
  switch ( newHeatLevel )
  {
    case 1u:
      UFG::PoliceScannerAudio::PlayScenario(this, "HeatLevel_One");
      break;
    case 2u:
      UFG::PoliceScannerAudio::PlayScenario(this, "HeatLevel_Two");
      break;
    case 3u:
      UFG::PoliceScannerAudio::PlayScenario(this, "HeatLevel_Three");
      break;
    case 4u:
      UFG::PoliceScannerAudio::PlayScenario(this, "HeatLevel_Four");
      break;
    case 5u:
      UFG::PoliceScannerAudio::PlayScenario(this, "HeatLevel_Five");
      break;
  }
}

