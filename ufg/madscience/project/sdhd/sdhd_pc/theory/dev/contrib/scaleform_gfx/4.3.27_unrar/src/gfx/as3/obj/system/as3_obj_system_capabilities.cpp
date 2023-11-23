// File Line: 42
// RVA: 0x91DDE0
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::avHardwareDisableGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        bool *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::avHardwareDisableGet() is not implemented\n");
}

// File Line: 55
// RVA: 0x920AD0
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasAudioGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        bool *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::hasAudioGet() is not implemented\n");
}

// File Line: 62
// RVA: 0x920AA0
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasAudioEncoderGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        bool *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::hasAudioEncoderGet() is not implemented\n");
}

// File Line: 69
// RVA: 0x920BE0
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasEmbeddedVideoGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        bool *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::hasEmbeddedVideoGet() is not implemented\n");
}

// File Line: 90
// RVA: 0x920CB0
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasMP3Get(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        bool *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::hasMP3Get() is not implemented\n");
}

// File Line: 115
// RVA: 0x920CE0
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasStreamingAudioGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        bool *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::hasStreamingAudioGet() is not implemented\n");
}

// File Line: 122
// RVA: 0x920D10
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasStreamingVideoGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        bool *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::hasStreamingVideoGet() is not implemented\n");
}

// File Line: 129
// RVA: 0x920D40
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasTLSGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        bool *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::hasTLSGet() is not implemented\n");
}

// File Line: 136
// RVA: 0x920D70
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasVideoEncoderGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        bool *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::hasVideoEncoderGet() is not implemented\n");
}

// File Line: 149
// RVA: 0x921310
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::languageGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::languageGet() is not implemented\n");
}

// File Line: 162
// RVA: 0x9214B0
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::manufacturerGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *StringNode; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASStringNode *v9; // rdi
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+50h] [rbp+8h] BYREF

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(result->pNode->pManager, "Scaleform ", 0xAui64);
  ++StringNode->RefCount;
  pNode = result->pNode;
  v6 = result->pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = StringNode;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    &resulta);
  v7 = Scaleform::GFx::ASStringManager::CreateStringNode(resulta.pNode->pManager, "Windows", 7ui64);
  ++v7->RefCount;
  v8 = resulta.pNode;
  v6 = resulta.pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  resulta.pNode = v7;
  v9 = Scaleform::GFx::ASStringManager::CreateStringNode(
         result->pNode->pManager,
         result->pNode->pData,
         result->pNode->Size,
         v7->pData,
         (Scaleform::GFx::ASStringNode *)v7->Size);
  ++v9->RefCount;
  v10 = result->pNode;
  v6 = result->pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  result->pNode = v9;
  v11 = resulta.pNode;
  v6 = resulta.pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
}

// File Line: 171
// RVA: 0x9219D0
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::osGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *StringNode; // rax
  Scaleform::GFx::ASStringNode *v4; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(result->pNode->pManager, "Windows", 7ui64);
  v4 = StringNode;
  ++StringNode->RefCount;
  pNode = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->pNode = v4;
  }
  else
  {
    result->pNode = StringNode;
  }
}

// File Line: 177
// RVA: 0x921B70
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::pixelAspectRatioGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        long double *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::pixelAspectRatioGet() is not implemented\n");
}

// File Line: 184
// RVA: 0x921BA0
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::playerTypeGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v3; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h] BYREF

  v3 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         this->pTraits.pObject->pVM->StringManagerRef,
         &resulta,
         "StandAlone");
  pNode = v3->pNode;
  ++v3->pNode->RefCount;
  v5 = result->pNode;
  v6 = result->pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  result->pNode = pNode;
  v7 = resulta.pNode;
  v6 = resulta.pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}

// File Line: 197
// RVA: 0x9234A0
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::screenColorGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::screenColorGet() is not implemented\n");
}

// File Line: 204
// RVA: 0x9234D0
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::screenDPIGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        long double *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::screenDPIGet() is not implemented\n");
}

// File Line: 211
// RVA: 0x923500
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::screenResolutionXGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        long double *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::screenResolutionXGet() is not implemented\n");
}

// File Line: 218
// RVA: 0x923530
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::screenResolutionYGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        long double *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::screenResolutionYGet() is not implemented\n");
}

// File Line: 225
// RVA: 0x923730
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::serverStringGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::Capabilities::serverStringGet() is not implemented\n");
}

// File Line: 232
// RVA: 0x927A40
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::Capabilities::versionGet(
        Scaleform::GFx::AS3::Classes::fl_system::Capabilities *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *StringNode; // rax
  Scaleform::GFx::ASStringNode *v4; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(result->pNode->pManager, "WIN 10,1,0,0", 0xCui64);
  v4 = StringNode;
  ++StringNode->RefCount;
  pNode = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->pNode = v4;
  }
  else
  {
    result->pNode = StringNode;
  }
}

// File Line: 330
// RVA: 0x1597C60
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_0_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F6B8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,0,bool>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::avHardwareDisableGet;
  return result;
}

// File Line: 331
// RVA: 0x1597A80
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_1_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F6C8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,1,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasScreenPlaybackGet;
  return result;
}

// File Line: 332
// RVA: 0x1597AB0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_2_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F6D8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,2,bool>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasAudioGet;
  return result;
}

// File Line: 333
// RVA: 0x1597AE0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_3_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F6E8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,3,bool>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasAudioEncoderGet;
  return result;
}

// File Line: 334
// RVA: 0x1597B10
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_4_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F6F8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,4,bool>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasEmbeddedVideoGet;
  return result;
}

// File Line: 335
// RVA: 0x1597B40
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_5_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F708 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,5,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasScreenPlaybackGet;
  return result;
}

// File Line: 336
// RVA: 0x1597B70
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_6_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F718 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,6,bool>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasMP3Get;
  return result;
}

// File Line: 337
// RVA: 0x1597BA0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_7_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F728 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,7,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasScreenPlaybackGet;
  return result;
}

// File Line: 338
// RVA: 0x1597BD0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_8_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F738 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,8,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasScreenPlaybackGet;
  return result;
}

// File Line: 339
// RVA: 0x1597C00
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_9_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F748 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,9,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasScreenPlaybackGet;
  return result;
}

// File Line: 340
// RVA: 0x1597C30
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_10_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F758 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,10,bool>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasStreamingAudioGet;
  return result;
}

// File Line: 341
// RVA: 0x1597EA0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_11_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F768 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,11,bool>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasStreamingVideoGet;
  return result;
}

// File Line: 342
// RVA: 0x1597ED0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_12_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F778 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,12,bool>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasTLSGet;
  return result;
}

// File Line: 343
// RVA: 0x1597F00
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_13_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F788 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,13,bool>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasVideoEncoderGet;
  return result;
}

// File Line: 344
// RVA: 0x1597F30
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_14_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F798 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,14,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasScreenPlaybackGet;
  return result;
}

// File Line: 345
// RVA: 0x1597F60
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_15_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F7A8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,15,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::languageGet;
  return result;
}

// File Line: 346
// RVA: 0x1597C90
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_16_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F7B8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,16,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_system::Capabilities *, bool *))Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasScreenPlaybackGet;
  return result;
}

// File Line: 347
// RVA: 0x1597CC0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_17_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F7C8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,17,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::manufacturerGet;
  return result;
}

// File Line: 348
// RVA: 0x1597CF0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_18_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F7D8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,18,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::osGet;
  return result;
}

// File Line: 349
// RVA: 0x1597D20
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_19_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F7E8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,19,double>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::pixelAspectRatioGet;
  return result;
}

// File Line: 350
// RVA: 0x1597D50
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_20_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F7F8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,20,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::playerTypeGet;
  return result;
}

// File Line: 351
// RVA: 0x1597D80
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_21_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F808 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,21,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::screenColorGet;
  return result;
}

// File Line: 352
// RVA: 0x1597DB0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_22_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F818 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,22,double>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::screenDPIGet;
  return result;
}

// File Line: 353
// RVA: 0x1597DE0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_23_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F828 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,23,double>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::screenResolutionXGet;
  return result;
}

// File Line: 354
// RVA: 0x1597E10
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_24_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F838 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,24,double>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::screenResolutionYGet;
  return result;
}

// File Line: 355
// RVA: 0x1597E40
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_25_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F848 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,25,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::serverStringGet;
  return result;
}

// File Line: 356
// RVA: 0x1597E70
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::Capabilities_26_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F858 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::Capabilities,26,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Classes::fl_system::Capabilities::versionGet;
  return result;
}

// File Line: 431
// RVA: 0x879DF0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_system::Capabilities::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rax
  Scaleform::GFx::AS3::Class *v11; // rdi

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  v7.pV = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, vm, &Scaleform::GFx::AS3::fl_system::CapabilitiesCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::Capabilities::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v8, vm, &Scaleform::GFx::AS3::fl_system::CapabilitiesCI);
    v7.pV = v9;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v7);
  v10 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                        MHeap,
                                        72i64);
  v11 = v10;
  if ( v10 )
  {
    Scaleform::GFx::AS3::Class::Class(v10, result->pV);
    v11->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_system::Capabilities::`vftable;
  }
  return result;
}

