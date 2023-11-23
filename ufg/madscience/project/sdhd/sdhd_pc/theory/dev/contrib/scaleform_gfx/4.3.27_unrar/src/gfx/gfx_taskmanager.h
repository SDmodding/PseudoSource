// File Line: 92
// RVA: 0x6D2780
void __fastcall Scaleform::GFx::Task::~Task(Scaleform::GFx::Task *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 158
// RVA: 0x6F6600
Scaleform::Ptr<Scaleform::GFx::TaskManager> *__fastcall Scaleform::GFx::StateBag::GetTaskManager(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::TaskManager> *result)
{
  result->pObject = (Scaleform::GFx::TaskManager *)this->vfptr->GetStateAddRef(this, 24i64);
  return result;
}

