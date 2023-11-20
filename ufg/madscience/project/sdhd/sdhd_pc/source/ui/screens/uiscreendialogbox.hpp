// File Line: 19
// RVA: 0x1529470
__int64 UFG::_dynamic_initializer_for__UI_HASH_DIALOG_BOX_APPEAR__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("DIALOG_BOX_APPEAR", 0xFFFFFFFF);
  UI_HASH_DIALOG_BOX_APPEAR = result;
  return result;
}

// File Line: 20
// RVA: 0x1529490
__int64 UFG::_dynamic_initializer_for__UI_HASH_DIALOG_BOX_DISAPPEAR__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("DIALOG_BOX_DISAPPEAR", 0xFFFFFFFF);
  UI_HASH_DIALOG_BOX_DISAPPEAR = result;
  return result;
}

// File Line: 58
// RVA: 0x5C8B30
void __fastcall UFG::UIScreenDialogBox::UIScreenDialogBoxData::UIScreenDialogBoxData(UFG::UIScreenDialogBox::UIScreenDialogBoxData *this)
{
  UFG::UIScreenDialogBox::UIScreenDialogBoxData *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::UICommandDataVtbl *)&UFG::UICommandData::`vftable';
  this->vfptr = (UFG::UICommandDataVtbl *)&UFG::UIScreenDialogBox::UIScreenDialogBoxData::`vftable';
  this->mOwner = 0i64;
  this->mDefaultButton = 1;
  UFG::qString::qString(&this->mTitleText);
  UFG::qString::qString(&v1->mBodyText);
  *(_QWORD *)&v1->mOption1Msg = 0i64;
  v1->mOption3Msg = 0;
  UFG::qString::qString(&v1->mOption1Text);
  UFG::qString::qString(&v1->mOption2Text);
  UFG::qString::qString(&v1->mOption3Text);
  v1->mIcon = 0;
  v1->mFullScreen = 1;
  UFG::qString::qString(&v1->mFlashFile);
}

