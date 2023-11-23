// File Line: 121
// RVA: 0x7825C0
void __fastcall Scaleform::GFx::AS3::StringManager::StringManager(
        Scaleform::GFx::AS3::StringManager *this,
        Scaleform::GFx::ASStringManager *pstrMgr)
{
  Scaleform::GFx::AS3::StringManager *v2; // rax
  __int64 v3; // r8

  v2 = this;
  v3 = 8i64;
  do
  {
    v2->Builtins[0].pNode = 0i64;
    v2->Builtins[1].pNode = 0i64;
    v2->Builtins[2].pNode = 0i64;
    v2 = (Scaleform::GFx::AS3::StringManager *)((char *)v2 + 64);
    v2[-1].Builtins[61].pNode = 0i64;
    v2[-1].Builtins[62].pNode = 0i64;
    v2[-1].Builtins[63].pNode = 0i64;
    v2[-1].pStringManager = 0i64;
    v2[-1].pStaticStrings = 0i64;
    --v3;
  }
  while ( v3 );
  this->pStringManager = pstrMgr;
  this->pStaticStrings = AS3BuiltinTable;
  Scaleform::GFx::ASStringManager::InitBuiltinArray(pstrMgr, this->Builtins, AS3BuiltinTable, 0x40u);
}

