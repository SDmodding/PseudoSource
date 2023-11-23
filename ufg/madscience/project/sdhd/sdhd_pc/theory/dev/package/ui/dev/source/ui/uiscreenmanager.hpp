// File Line: 75
// RVA: 0xA264A0
void __fastcall UFG::UIThreadCommandQueue::GetRenderInterfaces(
        UFG::UIThreadCommandQueue *this,
        Scaleform::Render::Interfaces *p)
{
  Scaleform::Render::TextureManager *v3; // rax

  p->pHAL = this->pHAL;
  p->pRenderer2D = this->pR2D;
  v3 = (Scaleform::Render::TextureManager *)((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->pHAL->vfptr[61].__vecDelDtor)(this->pHAL);
  p->RenderThreadID = 0i64;
  p->pTextureManager = v3;
}

// File Line: 219
// RVA: 0xA33B90
Scaleform::Ptr<Scaleform::Render::Renderer2D> *__fastcall UFG::UIScreenManagerBase::getRenderer2D(
        UFG::UIScreenManagerBase *this,
        Scaleform::Ptr<Scaleform::Render::Renderer2D> *result)
{
  Scaleform::Render::Renderer2D *pObject; // rcx

  pObject = this->mRenderer2D.pObject;
  if ( pObject )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pObject);
  result->pObject = (Scaleform::Render::Renderer2D *)this->mRenderer2D;
  return result;
}

