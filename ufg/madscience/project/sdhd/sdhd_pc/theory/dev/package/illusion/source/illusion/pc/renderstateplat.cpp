// File Line: 31
// RVA: 0xA1B270
void Illusion::HardwareState::Init(void)
{
  *(_DWORD *)Illusion::HardwareState::sBlendMode = 131073;
  word_142166D98 = 15;
  word_142166DA0 = 2;
  word_142166DA8 = 3;
  word_142166DB0 = 2;
  word_142166DE0 = 3;
  dword_142166DEC = 2;
  dword_142166DF0 = 3;
  dword_142166DF4 = 4;
  dword_142166DF8 = 5;
  dword_142166DFC = 6;
  dword_142166E00 = 7;
  dword_142166E04 = 8;
  dword_142166E4C = 10;
  dword_142166E68 = 11;
  dword_142166ED4 = 3;
  dword_142166ED8 = 2;
  dword_142166EDC = 4;
  dword_142166EE0 = 5;
  dword_142166EE4 = 5;
  dword_142166D84 = 262147;
  dword_142166D88 = 393221;
  dword_142166D8C = 524295;
  dword_142166D90 = 655369;
  dword_142166D94 = 917515;
  *(_DWORD *)Illusion::HardwareState::sCullMode = 196609;
  *(_DWORD *)Illusion::HardwareState::sCullModeI = 131073;
  *(_DWORD *)Illusion::HardwareState::sFillMode = 131075;
  *(_DWORD *)Illusion::HardwareState::sCompareFunction = 131073;
  dword_142166DBC = 262147;
  dword_142166DC0 = 393221;
  dword_142166DC4 = 524295;
  *(_DWORD *)Illusion::HardwareState::sCompareFunctionI = 458760;
  dword_142166DCC = 327686;
  dword_142166DD0 = 196612;
  dword_142166DD4 = 65538;
  *(_DWORD *)Illusion::HardwareState::sBlendEquation = 262145;
  dword_142166DDC = 131077;
  Illusion::HardwareState::sStencilOperation[0] = 1;
  Illusion::HardwareState::sTextureFormat[0] = 28;
  dword_142166E14 = 71;
  dword_142166E18 = 74;
  qword_142166E1C = 77i64;
  dword_142166E48 = 41;
  dword_142166E24 = 0;
  qword_142166E50 = 44i64;
  dword_142166E58 = 44;
  dword_142166E5C = 44;
  dword_142166E28 = 61;
  dword_142166E2C = 56;
  dword_142166E30 = 71;
  dword_142166E34 = 83;
  dword_142166E60 = 24;
  dword_142166E64 = 26;
  dword_142166E38 = 95;
  dword_142166E3C = 96;
  dword_142166E40 = 98;
  dword_142166E44 = 99;
  Illusion::HardwareState::sPrimType[0] = 1;
  dword_142166EEC = 33;
  dword_142166EF0 = 34;
  dword_142166EF4 = 35;
  dword_142166EF8 = 36;
  dword_142166EFC = 37;
  dword_142166F00 = 38;
  dword_142166F04 = 39;
  dword_142166F08 = 40;
  dword_142166F0C = 41;
  dword_142166F10 = 42;
  dword_142166F14 = 43;
  dword_142166F18 = 44;
  dword_142166F1C = 45;
  dword_142166F20 = 46;
  dword_142166F24 = 47;
  dword_142166F28 = 48;
  dword_142166F2C = 49;
  dword_142166F30 = 50;
  dword_142166F34 = 51;
  dword_142166F38 = 52;
  dword_142166F3C = 53;
  dword_142166F40 = 54;
  dword_142166F44 = 55;
  dword_142166F48 = 56;
  dword_142166F4C = 57;
  dword_142166F50 = 58;
  dword_142166F54 = 59;
  dword_142166F58 = 60;
  dword_142166F5C = 61;
  dword_142166F60 = 62;
  dword_142166F64 = 63;
  dword_142166F68 = 64;
}

// File Line: 166
// RVA: 0xA1E180
void __fastcall Illusion::AlphaState::OnAddPlat(Illusion::AlphaState *this)
{
  Illusion::AlphaStatePlat::OnAdd((Illusion::AlphaStatePlat *)&this[1]);
}

// File Line: 172
// RVA: 0xA1EDC0
void __fastcall Illusion::AlphaState::OnRemovePlat(Illusion::AlphaState *this)
{
  UFG::qBaseNodeRB *mParent; // rcx

  mParent = this[1].mNode.mParent;
  if ( mParent )
  {
    ((void (__fastcall *)(UFG::qBaseNodeRB *))mParent->mParent->mChild[1])(mParent);
    this[1].mNode.mParent = 0i64;
  }
}

// File Line: 181
// RVA: 0xA1DE90
void __fastcall Illusion::AlphaStatePlat::OnAdd(Illusion::AlphaStatePlat *this)
{
  __int64 v2; // rdx
  __int64 v3; // r8
  char mD3DBlendState; // r9
  bool v5; // zf
  char v6; // dl
  __int64 Dst[35]; // [rsp+20h] [rbp-118h] BYREF

  memset(Dst, 0, 0x108ui64);
  v2 = BYTE1(this[-3].mD3DBlendState);
  v3 = BYTE2(this[-3].mD3DBlendState);
  mD3DBlendState = (char)this[-2].mD3DBlendState;
  v5 = LOBYTE(this[-3].mD3DBlendState) == 0;
  Dst[0] = 0i64;
  LODWORD(Dst[1]) = !v5;
  HIDWORD(Dst[1]) = Illusion::HardwareState::sBlendMode[v2];
  LODWORD(Dst[2]) = Illusion::HardwareState::sBlendMode[v3];
  HIDWORD(Dst[2]) = Illusion::HardwareState::sBlendEquation[BYTE3(this[-3].mD3DBlendState)];
  if ( mD3DBlendState )
  {
    LOBYTE(v2) = BYTE1(this[-2].mD3DBlendState);
  }
  else
  {
    switch ( (_DWORD)v2 )
    {
      case 2:
        LOBYTE(v2) = 4;
        break;
      case 3:
        LOBYTE(v2) = 5;
        break;
      case 8:
        LOBYTE(v2) = 6;
        break;
      case 9:
        LOBYTE(v2) = 7;
        break;
    }
  }
  LODWORD(Dst[3]) = Illusion::HardwareState::sBlendMode[(unsigned __int8)v2];
  if ( mD3DBlendState )
  {
    LOBYTE(v3) = BYTE2(this[-2].mD3DBlendState);
  }
  else
  {
    switch ( (_DWORD)v3 )
    {
      case 2:
        LOBYTE(v3) = 4;
        break;
      case 3:
        LOBYTE(v3) = 5;
        break;
      case 8:
        LOBYTE(v3) = 6;
        break;
      case 9:
        LOBYTE(v3) = 7;
        break;
    }
  }
  v6 = BYTE3(this[-2].mD3DBlendState);
  HIDWORD(Dst[3]) = Illusion::HardwareState::sBlendMode[(unsigned __int8)v3];
  LODWORD(Dst[4]) = Illusion::HardwareState::sBlendEquation[BYTE4(this[-3].mD3DBlendState)];
  BYTE4(Dst[4]) |= v6 & 8 | v6 & 4 | v6 & 2 | v6 & 1;
  ((void (__fastcall *)(ID3D11Device *, __int64 *, Illusion::AlphaStatePlat *))UFG::gD3D11Device->vfptr->VSSetSamplers)(
    UFG::gD3D11Device,
    Dst,
    this);
}

// File Line: 220
// RVA: 0xA1E190
void __fastcall Illusion::RasterState::OnAddPlat(Illusion::RasterState *this)
{
  Illusion::RasterStatePlat::OnAdd((Illusion::RasterStatePlat *)&this[1]);
}

// File Line: 226
// RVA: 0xA1EDF0
void __fastcall Illusion::RasterState::OnRemovePlat(Illusion::RasterState *this)
{
  UFG::qBaseNodeRB *v2; // rcx
  UFG::qBaseNodeRB *mParent; // rcx

  v2 = this[1].mNode.mChild[0];
  if ( v2 )
  {
    ((void (__fastcall *)(UFG::qBaseNodeRB *))v2->mParent->mChild[1])(v2);
    this[1].mNode.mChild[0] = 0i64;
  }
  mParent = this[1].mNode.mParent;
  if ( mParent )
  {
    ((void (__fastcall *)(UFG::qBaseNodeRB *))mParent->mParent->mChild[1])(mParent);
    this[1].mNode.mParent = 0i64;
  }
}

// File Line: 234
// RVA: 0xA1DFE0
void __fastcall Illusion::RasterStatePlat::OnAdd(Illusion::RasterStatePlat *this)
{
  __int64 mD3DRasterizerState_low; // rdx
  __int64 v3; // r8
  __int64 mD3DDepthState_high; // r9
  __int64 v5; // r10
  char v6; // cl
  int v7; // eax
  __int64 v8; // rax
  __int64 v9[5]; // [rsp+20h] [rbp-60h] BYREF
  int Dst[14]; // [rsp+48h] [rbp-38h] BYREF

  memset(Dst, 0, 0x34ui64);
  mD3DRasterizerState_low = LOBYTE(this[-2].mD3DRasterizerState);
  v3 = BYTE1(this[-2].mD3DRasterizerState);
  mD3DDepthState_high = HIBYTE(this[-2].mD3DDepthState);
  v5 = BYTE6(this[-2].mD3DDepthState);
  v6 = BYTE2(this[-2].mD3DRasterizerState);
  LOBYTE(Dst[4]) = -1;
  Dst[0] = LOBYTE(this[-3].mD3DRasterizerState) != 0;
  Dst[1] = BYTE1(this[-3].mD3DRasterizerState) != 0;
  Dst[2] = Illusion::HardwareState::sCompareFunction[BYTE2(this[-3].mD3DRasterizerState)];
  Dst[3] = BYTE6(this[-3].mD3DRasterizerState) != 0;
  BYTE1(Dst[4]) = BYTE1(this[-1].mD3DDepthState);
  Dst[5] = Illusion::HardwareState::sStencilOperation[mD3DRasterizerState_low];
  Dst[6] = Illusion::HardwareState::sStencilOperation[v3];
  Dst[7] = Illusion::HardwareState::sStencilOperation[mD3DDepthState_high];
  Dst[8] = Illusion::HardwareState::sCompareFunction[v5];
  if ( v6 )
    LOBYTE(mD3DRasterizerState_low) = HIBYTE(this[-2].mD3DRasterizerState);
  Dst[9] = Illusion::HardwareState::sStencilOperation[(unsigned __int8)mD3DRasterizerState_low];
  if ( v6 )
    LOBYTE(v3) = this[-1].mD3DDepthState;
  Dst[10] = Illusion::HardwareState::sStencilOperation[(unsigned __int8)v3];
  if ( v6 )
    LOBYTE(mD3DDepthState_high) = BYTE6(this[-2].mD3DRasterizerState);
  Dst[11] = Illusion::HardwareState::sStencilOperation[(unsigned __int8)mD3DDepthState_high];
  if ( v6 )
    LOBYTE(v5) = BYTE5(this[-2].mD3DRasterizerState);
  Dst[12] = Illusion::HardwareState::sCompareFunction[(unsigned __int8)v5];
  ((void (__fastcall *)(ID3D11Device *, int *, Illusion::RasterStatePlat *))UFG::gD3D11Device->vfptr->SetPredication)(
    UFG::gD3D11Device,
    Dst,
    this);
  memset(v9, 0, sizeof(v9));
  v7 = Illusion::HardwareState::sFillMode[BYTE2(this[-1].mD3DDepthState)];
  v9[1] = 1i64;
  v9[2] = 0i64;
  LODWORD(v9[0]) = v7;
  v8 = BYTE3(this[-3].mD3DRasterizerState);
  LODWORD(v9[3]) = 1;
  LODWORD(v8) = Illusion::HardwareState::sCullMode[v8];
  *(__int64 *)((char *)&v9[3] + 4) = 1i64;
  HIDWORD(v9[4]) = 0;
  HIDWORD(v9[0]) = v8;
  ((void (__fastcall *)(ID3D11Device *, __int64 *, ID3D11RasterizerState **))UFG::gD3D11Device->vfptr->GSSetShaderResources)(
    UFG::gD3D11Device,
    v9,
    &this->mD3DRasterizerState);
}

