// File Line: 31
// RVA: 0x8E9450
void __fastcall Scaleform::GFx::LogState::LogMessageVarg(
        Scaleform::GFx::LogState *this,
        int *messageType,
        const char *fmt,
        char *argList)
{
  Scaleform::Log *pObject; // rcx
  int v8; // [rsp+30h] [rbp+8h] BYREF

  pObject = this->pLog.pObject;
  if ( pObject || (pObject = Scaleform::Log::GetGlobalLog()) != 0i64 )
  {
    v8 = *messageType;
    ((void (__fastcall *)(Scaleform::Log *, int *, const char *, char *))pObject->vfptr[1].__vecDelDtor)(
      pObject,
      &v8,
      fmt,
      argList);
  }
}

// File Line: 52
// RVA: 0x8DAD10
Scaleform::Ptr<Scaleform::GFx::LogState> *__fastcall Scaleform::GFx::StateBag::GetLogState(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::LogState> *result)
{
  result->pObject = (Scaleform::GFx::LogState *)this->vfptr->GetStateAddRef(this, 2i64);
  return result;
}

// File Line: 57
// RVA: 0x908B80
void __fastcall Scaleform::GFx::StateBag::SetLog(Scaleform::GFx::StateBag *this, Scaleform::GFx::Resource *log)
{
  Scaleform::GFx::LogState *v4; // rax
  Scaleform::GFx::State *v5; // rax
  Scaleform::GFx::State *v6; // rbx

  v4 = (Scaleform::GFx::LogState *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                     Scaleform::Memory::pGlobalHeap,
                                     40i64);
  if ( v4 )
  {
    Scaleform::GFx::LogState::LogState(v4, log);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  this->vfptr->SetState(this, State_Scale9, v6);
  if ( v6 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v6);
}

// File Line: 62
// RVA: 0x8DAC80
Scaleform::Ptr<Scaleform::Log> *__fastcall Scaleform::GFx::StateBag::GetLog(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::Log> *result)
{
  Scaleform::Render::RenderBuffer *v3; // rsi
  Scaleform::GFx::Resource *pRenderTargetData; // rbx

  v3 = (Scaleform::Render::RenderBuffer *)this->vfptr->GetStateAddRef(this, 2i64);
  pRenderTargetData = (Scaleform::GFx::Resource *)v3->pRenderTargetData;
  if ( pRenderTargetData || (pRenderTargetData = (Scaleform::GFx::Resource *)Scaleform::Log::GetGlobalLog()) != 0i64 )
    Scaleform::Render::RenderBuffer::AddRef(pRenderTargetData);
  result->pObject = (Scaleform::Log *)pRenderTargetData;
  Scaleform::RefCountImpl::Release(v3);
  return result;
}

