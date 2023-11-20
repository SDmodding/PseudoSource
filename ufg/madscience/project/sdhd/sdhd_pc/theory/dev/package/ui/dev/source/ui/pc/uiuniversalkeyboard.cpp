// File Line: 20
// RVA: 0x15ACEF0
__int64 dynamic_initializer_for__UFG::UIUniversalKeyboard::mInitData__()
{
  UFG::qString::qString(&UFG::UIUniversalKeyboard::mInitData.mTitle, &customWorldMapCaption);
  UFG::qString::qString(&stru_14249C6B8, &customWorldMapCaption);
  *(_QWORD *)&dword_14249C6E0 = 0i64;
  unk_14249C6E8 = 127;
  unk_14249C6EC = -1;
  unk_14249C6F0 = 0;
  return atexit(dynamic_atexit_destructor_for__UFG::UIUniversalKeyboard::mInitData__);
}

