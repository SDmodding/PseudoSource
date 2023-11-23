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
  ID3D11PixelShader *pObject; // rcx

  this->pProg.pObject = 0i64;
  pObject = this->pProg.pObject;
  if ( pObject )
    pObject->vfptr->Release(pObject);
  this->pProg.pObject = 0i64;
  this->Offset = 0i64;
}

// File Line: 54
// RVA: 0x9FBC10
void __fastcall Scaleform::Render::D3D1x::VertexShader::~VertexShader(Scaleform::Render::D3D1x::VertexShader *this)
{
  ID3D11VertexShader *pObject; // rcx

  Scaleform::Render::D3D1x::VertexShader::Shutdown(this);
  pObject = this->pProg.pObject;
  if ( pObject )
    pObject->vfptr->Release(pObject);
}

// File Line: 134
// RVA: 0xA09830
__int64 __fastcall Scaleform::Render::D3D1x::ShaderManager::GetShaderVersion(
        Scaleform::Render::D3D1x::ShaderManager *this)
{
  return (unsigned int)this->ShaderModel;
}

