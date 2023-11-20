// File Line: 33
// RVA: 0x2E62E0
void __fastcall UFG::UICommandData::operator delete(void *ptr, const char *name)
{
  UFG::qMemoryPool::Free(&gScaleformMemoryPool, ptr);
}

// File Line: 39
// RVA: 0x2E5870
void __fastcall UFG::UIScreenInvoke::~UIScreenInvoke(UFG::UIScreenInvoke *this)
{
  UFG::UIScreenInvoke *v1; // rbx
  UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *v2; // rdx
  UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *v3; // rcx
  UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *v4; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable';
  UFG::qString::~qString(&this->command);
  v2 = (UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
}

// File Line: 60
// RVA: 0x2E2230
void __fastcall UFG::UIScreenInvokeValueArgs::UIScreenInvokeValueArgs(UFG::UIScreenInvokeValueArgs *this)
{
  UFG::UIScreenInvokeValueArgs *v1; // rbx
  UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *v2; // rax

  v1 = this;
  v2 = (UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable';
  UFG::qString::qString(&this->command, &customWorldMapCaption);
  v1->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvokeValueArgs::`vftable';
  v1->args = 0i64;
  v1->numArgs = 0;
  v1->tempStrings = 0i64;
}

// File Line: 63
// RVA: 0x2E58C0
void __fastcall UFG::UIScreenInvokeValueArgs::~UIScreenInvokeValueArgs(UFG::UIScreenInvokeValueArgs *this)
{
  UFG::UIScreenInvokeValueArgs *v1; // rdi
  Scaleform::GFx::Value *v2; // rcx
  unsigned __int64 *v3; // rbx
  UFG::qString *v4; // rcx
  unsigned int *v5; // rbx
  UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *v6; // rdx
  UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *v7; // rcx
  UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *v8; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvokeValueArgs::`vftable';
  v2 = this->args;
  if ( v2 )
  {
    v3 = &v2[-1].DataAux;
    `eh vector destructor iterator'(
      v2,
      0x30ui64,
      v2[-1].DataAux,
      (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    operator delete[](v3);
  }
  v4 = v1->tempStrings;
  if ( v4 )
  {
    v5 = &v4[-1].mStringHash32;
    `eh vector destructor iterator'(
      v4,
      0x28ui64,
      v4[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v5);
  }
  v1->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable';
  UFG::qString::~qString(&v1->command);
  v6 = (UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *)&v1->mPrev;
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v6->mPrev = v6;
  v6->mNext = v6;
}

// File Line: 92
// RVA: 0x5C8BE0
void __fastcall UFG::UIScreenInvokeStringArgs::UIScreenInvokeStringArgs(UFG::UIScreenInvokeStringArgs *this)
{
  UFG::UIScreenInvokeStringArgs *v1; // rbx
  UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *v2; // rax

  v1 = this;
  v2 = (UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable';
  UFG::qString::qString(&this->command, &customWorldMapCaption);
  v1->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvokeStringArgs::`vftable';
  UFG::qString::qString(&v1->args, &customWorldMapCaption);
  v1->numArgs = 0;
}

