// File Line: 34
// RVA: 0x15549E0
__int64 dynamic_initializer_for__Phoneme_Ee::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Phoneme_Ee", 0xFFFFFFFF);
  Phoneme_Ee::sClassNameUID = result;
  return result;
}

// File Line: 43
// RVA: 0x1554A00
__int64 dynamic_initializer_for__Phoneme_Eh::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Phoneme_Eh", 0xFFFFFFFF);
  Phoneme_Eh::sClassNameUID = result;
  return result;
}

// File Line: 52
// RVA: 0x1554A80
__int64 dynamic_initializer_for__Phoneme_Rr::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Phoneme_Rr", 0xFFFFFFFF);
  Phoneme_Rr::sClassNameUID = result;
  return result;
}

// File Line: 61
// RVA: 0x1554A20
__int64 dynamic_initializer_for__Phoneme_Fr::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Phoneme_Fr", 0xFFFFFFFF);
  Phoneme_Fr::sClassNameUID = result;
  return result;
}

// File Line: 70
// RVA: 0x1554A40
__int64 dynamic_initializer_for__Phoneme_Mm::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Phoneme_Mm", 0xFFFFFFFF);
  Phoneme_Mm::sClassNameUID = result;
  return result;
}

// File Line: 79
// RVA: 0x15549A0
__int64 dynamic_initializer_for__Phoneme_A0::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Phoneme_A0", 0xFFFFFFFF);
  Phoneme_A0::sClassNameUID = result;
  return result;
}

// File Line: 88
// RVA: 0x15549C0
__int64 dynamic_initializer_for__Phoneme_AA::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Phoneme_AA", 0xFFFFFFFF);
  Phoneme_AA::sClassNameUID = result;
  return result;
}

// File Line: 97
// RVA: 0x1554A60
__int64 dynamic_initializer_for__Phoneme_OW::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Phoneme_OW", 0xFFFFFFFF);
  Phoneme_OW::sClassNameUID = result;
  return result;
}

// File Line: 110
// RVA: 0x155CD10
const char *dynamic_initializer_for__sPhonemeFactoryList__()
{
  const char *result; // rax

  sPhonemeFactoryList[0].mClassName = Phoneme_Ee::sClassName;
  sPhonemeFactoryList[1].mClassName = Phoneme_Eh::sClassName;
  sPhonemeFactoryList[2].mClassName = Phoneme_Rr::sClassName;
  sPhonemeFactoryList[3].mClassName = Phoneme_Fr::sClassName;
  sPhonemeFactoryList[4].mClassName = Phoneme_Mm::sClassName;
  sPhonemeFactoryList[5].mClassName = Phoneme_A0::sClassName;
  sPhonemeFactoryList[6].mClassName = Phoneme_AA::sClassName;
  result = Phoneme_OW::sClassName;
  sPhonemeFactoryList[7].mClassName = Phoneme_OW::sClassName;
  return result;
}

// File Line: 127
// RVA: 0x1559CE0
__int64 dynamic_initializer_for__gPhonemeFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(&gPhonemeFactory, sPhonemeFactoryList, sPhonemeFactoryListNum);
  return atexit(dynamic_atexit_destructor_for__gPhonemeFactory__);
}

// File Line: 132
// RVA: 0x155CCA0
const char *dynamic_initializer_for__sDialogTrackFactoryList__()
{
  const char *result; // rax

  sDialogTrackFactoryList[0].mClassName = TargetActionRequestTrack::sClassName;
  sDialogTrackFactoryList[1].mClassName = ActionRequestTrack::sClassName;
  sDialogTrackFactoryList[2].mClassName = SubtitleTrack::sClassName;
  result = ConversationTrackInterrupt::sClassName;
  sDialogTrackFactoryList[3].mClassName = ConversationTrackInterrupt::sClassName;
  return result;
}

// File Line: 138
// RVA: 0x1559C90
__int64 dynamic_initializer_for__gDialogTrackFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(
    &gDialogTrackFactory,
    sDialogTrackFactoryList,
    sDialogTrackFactoryListNum);
  return atexit(dynamic_atexit_destructor_for__gDialogTrackFactory__);
}

