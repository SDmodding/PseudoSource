// File Line: 39
// RVA: 0xA091C0
void __fastcall Scaleform::Render::D3D1x::VertexShader::VertexShader(Scaleform::Render::D3D1x::VertexShader *this)
{
  this->pDesc = 0i64;
  this->pProg.pObject = 0i64;
}

// File Line: 53
// RVA: 0xA08E60
void __fastcall Scaleform::Render::D3D1x::FragShader::FragShader(Scaleform::Render::D3D1x::FragShader *this)
{
  Scaleform::Render::D3D1x::FragShader *v1; // rbx
  ID3D11PixelShader *v2; // rcx

  v1 = this;
  this->pProg.pObject = 0i64;
  v2 = this->pProg.pObject;
  if ( v2 )
    ((void (__cdecl *)(ID3D11PixelShader *))v2->vfptr->Release)(v2);
  v1->pProg.pObject = 0i64;
  v1->Offset = 0i64;
}

// File Line: 54
// RVA: 0x9FBC10
void __fastcall Scaleform::Render::D3D1x::VertexShader::~VertexShader(Scaleform::Render::D3D1x::VertexShader *this)
{
  Scaleform::Render::D3D1x::VertexShader *v1; // rbx
  ID3D11VertexShader *v2; // rcx

  v1 = this;
  Scaleform::Render::D3D1x::VertexShader::Shutdown(this);
  v2 = v1->pProg.pObject;
  if ( v2 )
    ((void (*)(void))v2->vfptr->Release)();
}

// File Line: 134
// RVA: 0xA09830
__int64 __fastcall Scaleform::Render::D3D1x::ShaderManager::GetShaderVersion(Scaleform::Render::D3D1x::ShaderManager *this)
{
  return (unsigned int)this->ShaderModel;
}

