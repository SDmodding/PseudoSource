// File Line: 24
// RVA: 0xA25CB0
void __fastcall UFG::UIGfxFsCommandHandler::Callback(UFG::UIGfxFsCommandHandler *this, Scaleform::GFx::Movie *movie, const char *command, const char *arg)
{
  const char *v4; // rsi
  const char *v5; // rbp
  Scaleform::GFx::Movie *v6; // r14
  char v7; // di
  UFG::allocator::free_link *v8; // rbx
  int v9; // eax
  UFG::allocator::free_link *v10; // rcx
  UFG::qString text; // [rsp+48h] [rbp-30h]

  v4 = arg;
  v5 = command;
  v6 = movie;
  v7 = 0;
  v8 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x68ui64, "UIGfxFsCommandHandler::Callback", 0i64, 1u);
  if ( v8 )
  {
    UFG::qString::qString(&text, v4);
    v7 = 1;
    v9 = UFG::qStringHashUpper32(v5, 0xFFFFFFFF);
    v10 = v8 + 1;
    v10->mNext = v10;
    v10[1].mNext = v10;
    v8->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
    LODWORD(v8[3].mNext) = -1;
    v8[4].mNext = 0i64;
    v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
    LODWORD(v8[5].mNext) = v9;
    HIDWORD(v8[5].mNext) = 0;
    v8[6].mNext = (UFG::allocator::free_link *)-1i64;
    LODWORD(v8[3].mNext) = 5;
    v8->mNext = (UFG::allocator::free_link *)&UFG::UIMessageFlash::`vftable;
    UFG::qString::qString((UFG::qString *)&v8[7], &text);
    v8[12].mNext = (UFG::allocator::free_link *)v6;
    LODWORD(v8[3].mNext) = 7;
    HIDWORD(v8[6].mNext) = 4;
  }
  else
  {
    v8 = 0i64;
  }
  if ( v7 & 1 )
    UFG::qString::~qString(&text);
  UFG::UIScreenManagerBase::queueMessageEx(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    (UFG::UIMessage *)v8);
}

