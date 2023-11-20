// File Line: 31
// RVA: 0x8E9450
void __fastcall Scaleform::GFx::LogState::LogMessageVarg(Scaleform::GFx::LogState *this, __int64 messageType, const char *fmt, char *argList)
{
  Scaleform::Log *v4; // rcx
  char *v5; // rbx
  const char *v6; // rdi
  int *v7; // rsi
  int v8; // [rsp+30h] [rbp+8h]

  v4 = this->pLog.pObject;
  v5 = argList;
  v6 = fmt;
  v7 = (int *)messageType;
  if ( v4 || (v4 = Scaleform::Log::GetGlobalLog()) != 0i64 )
  {
    v8 = *v7;
    ((void (__fastcall *)(Scaleform::Log *, int *, const char *, char *))v4->vfptr[1].__vecDelDtor)(v4, &v8, v6, v5);
  }
}

// File Line: 52
// RVA: 0x8DAD10
Scaleform::Ptr<Scaleform::GFx::LogState> *__fastcall Scaleform::GFx::StateBag::GetLogState(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::LogState> *result)
{
  Scaleform::Ptr<Scaleform::GFx::LogState> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::LogState *)this->vfptr->GetStateAddRef(this, State_Scale9);
  return v2;
}

// File Line: 57
// RVA: 0x908B80
void __fastcall Scaleform::GFx::StateBag::SetLog(Scaleform::GFx::StateBag *this, Scaleform::Log *log)
{
  Scaleform::Log *v2; // rbx
  Scaleform::GFx::StateBag *v3; // rdi
  Scaleform::GFx::LogState *v4; // rax
  Scaleform::Render::RenderBuffer *v5; // rax
  Scaleform::Render::RenderBuffer *v6; // rbx

  v2 = log;
  v3 = this;
  v4 = (Scaleform::GFx::LogState *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                     Scaleform::Memory::pGlobalHeap,
                                     40i64);
  if ( v4 )
  {
    Scaleform::GFx::LogState::LogState(v4, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v3->vfptr->SetState(v3, State_Scale9, (Scaleform::GFx::State *)v6);
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
}

// File Line: 62
// RVA: 0x8DAC80
Scaleform::Ptr<Scaleform::Log> *__fastcall Scaleform::GFx::StateBag::GetLog(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::Log> *result)
{
  Scaleform::Ptr<Scaleform::Log> *v2; // rdi
  Scaleform::Render::RenderBuffer *v3; // rsi
  Scaleform::GFx::Resource *v4; // rbx

  v2 = result;
  v3 = (Scaleform::Render::RenderBuffer *)this->vfptr->GetStateAddRef(this, State_Scale9);
  v4 = (Scaleform::GFx::Resource *)v3->pRenderTargetData;
  if ( v4 || (v4 = (Scaleform::GFx::Resource *)Scaleform::Log::GetGlobalLog()) != 0i64 )
    Scaleform::Render::RenderBuffer::AddRef(v4);
  v2->pObject = (Scaleform::Log *)v4;
  Scaleform::RefCountImpl::Release(v3);
  return v2;
}

