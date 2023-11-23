// File Line: 33
// RVA: 0x2E62E0
void __fastcall UFG::UICommandData::operator delete(char *ptr, const char *name)
{
  UFG::qMemoryPool::Free(&gScaleformMemoryPool, ptr);
}

// File Line: 39
// RVA: 0x2E5870
void __fastcall UFG::UIScreenInvoke::~UIScreenInvoke(UFG::UIScreenInvoke *this)
{
  UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *mPrev; // rcx
  UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *mNext; // rax

  this->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable;
  UFG::qString::~qString(&this->command);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke>;
  this->mNext = &this->UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke>;
}

// File Line: 60
// RVA: 0x2E2230
void __fastcall UFG::UIScreenInvokeValueArgs::UIScreenInvokeValueArgs(UFG::UIScreenInvokeValueArgs *this)
{
  this->mPrev = &this->UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke>;
  this->mNext = &this->UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke>;
  this->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable;
  UFG::qString::qString(&this->command, &customCaption);
  this->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvokeValueArgs::`vftable;
  this->args = 0i64;
  this->numArgs = 0;
  this->tempStrings = 0i64;
}

// File Line: 63
// RVA: 0x2E58C0
void __fastcall UFG::UIScreenInvokeValueArgs::~UIScreenInvokeValueArgs(UFG::UIScreenInvokeValueArgs *this)
{
  Scaleform::GFx::Value *args; // rcx
  unsigned __int64 *p_DataAux; // rbx
  UFG::qString *tempStrings; // rcx
  unsigned int *p_mStringHash32; // rbx
  UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *mPrev; // rcx
  UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *mNext; // rax

  this->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvokeValueArgs::`vftable;
  args = this->args;
  if ( args )
  {
    p_DataAux = &args[-1].DataAux;
    `eh vector destructor iterator(
      args,
      0x30ui64,
      args[-1].DataAux,
      (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    operator delete[](p_DataAux);
  }
  tempStrings = this->tempStrings;
  if ( tempStrings )
  {
    p_mStringHash32 = &tempStrings[-1].mStringHash32;
    `eh vector destructor iterator(
      tempStrings,
      0x28ui64,
      tempStrings[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
  }
  this->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable;
  UFG::qString::~qString(&this->command);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke>;
  this->mNext = &this->UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke>;
}

// File Line: 92
// RVA: 0x5C8BE0
void __fastcall UFG::UIScreenInvokeStringArgs::UIScreenInvokeStringArgs(UFG::UIScreenInvokeStringArgs *this)
{
  this->mPrev = &this->UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke>;
  this->mNext = &this->UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke>;
  this->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable;
  UFG::qString::qString(&this->command, &customCaption);
  this->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvokeStringArgs::`vftable;
  UFG::qString::qString(&this->args, &customCaption);
  this->numArgs = 0;
}

