// File Line: 19
// RVA: 0x1529470
__int64 UFG::_dynamic_initializer_for__UI_HASH_DIALOG_BOX_APPEAR__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("DIALOG_BOX_APPEAR", -1);
  UI_HASH_DIALOG_BOX_APPEAR = result;
  return result;
}

// File Line: 20
// RVA: 0x1529490
__int64 UFG::_dynamic_initializer_for__UI_HASH_DIALOG_BOX_DISAPPEAR__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("DIALOG_BOX_DISAPPEAR", -1);
  UI_HASH_DIALOG_BOX_DISAPPEAR = result;
  return result;
}

// File Line: 58
// RVA: 0x5C8B30
void __fastcall UFG::UIScreenDialogBox::UIScreenDialogBoxData::UIScreenDialogBoxData(
        UFG::UIScreenDialogBox::UIScreenDialogBoxData *this)
{
  this->vfptr = (UFG::UICommandDataVtbl *)&UFG::UICommandData::`vftable;
  this->vfptr = (UFG::UICommandDataVtbl *)&UFG::UIScreenDialogBox::UIScreenDialogBoxData::`vftable;
  this->mOwner = 0i64;
  this->mDefaultButton = DIALOG_BUTTON1;
  UFG::qString::qString(&this->mTitleText);
  UFG::qString::qString(&this->mBodyText);
  *(_QWORD *)&this->mOption1Msg = 0i64;
  this->mOption3Msg = 0;
  UFG::qString::qString(&this->mOption1Text);
  UFG::qString::qString(&this->mOption2Text);
  UFG::qString::qString(&this->mOption3Text);
  this->mIcon = 0;
  this->mFullScreen = 1;
  UFG::qString::qString(&this->mFlashFile);
}

