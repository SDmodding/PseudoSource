// File Line: 216
// RVA: 0x6CBC50
void __fastcall Scaleform::GFx::AS2::StringManager::StringManager(Scaleform::GFx::AS2::StringManager *this, Scaleform::GFx::ASStringManager *pstrMgr)
{
  Scaleform::GFx::AS2::StringManager *v2; // rax
  signed __int64 v3; // r8

  v2 = this;
  v3 = 19i64;
  do
  {
    v2->Builtins[0].pNode = 0i64;
    v2->Builtins[1].pNode = 0i64;
    v2->Builtins[2].pNode = 0i64;
    v2 = (Scaleform::GFx::AS2::StringManager *)((char *)v2 + 64);
    v2[-1].Builtins[153].pNode = 0i64;
    v2[-1].Builtins[154].pNode = 0i64;
    v2[-1].Builtins[155].pNode = 0i64;
    v2[-1].pStringManager = 0i64;
    v2[-1].pStaticStrings = 0i64;
    --v3;
  }
  while ( v3 );
  v2->Builtins[0].pNode = 0i64;
  v2->Builtins[1].pNode = 0i64;
  v2->Builtins[2].pNode = 0i64;
  v2->Builtins[3].pNode = 0i64;
  this->pStringManager = pstrMgr;
  this->pStaticStrings = GFx_pASBuiltinTable;
  Scaleform::GFx::ASStringManager::InitBuiltinArray(pstrMgr, this->Builtins, GFx_pASBuiltinTable, 0x9Cu);
}

