// File Line: 12
// RVA: 0xEF53C0
__int64 __fastcall ssl_verify_cert_win(const char *buffer, int bufferSize)
{
  int v2; // er15
  const char *v3; // r14
  int v4; // ebx
  _CERT_CONTEXT *v5; // rsi
  HCERTSTORE i; // r12
  int v7; // ebx
  __int64 v8; // rcx
  int v9; // ebx
  DWORD v10; // edi
  unsigned int v11; // ebx
  PCCERT_CHAIN_CONTEXT pChainContext; // [rsp+40h] [rbp-49h]
  _CERT_CHAIN_POLICY_PARA pPolicyPara; // [rsp+48h] [rbp-41h]
  _CERT_CHAIN_PARA pChainPara; // [rsp+58h] [rbp-31h]
  int v16; // [rsp+78h] [rbp-11h]
  int Dst; // [rsp+7Ch] [rbp-Dh]
  char *v18; // [rsp+88h] [rbp-1h]
  _CERT_CHAIN_POLICY_STATUS pPolicyStatus; // [rsp+90h] [rbp+7h]
  const char *v20; // [rsp+A8h] [rbp+1Fh]

  v2 = bufferSize;
  v3 = buffer;
  v4 = 0;
  v5 = 0i64;
  for ( i = CertOpenStore((LPCSTR)2, 0, 0i64, 0, 0i64); v4 < v2; v4 = v10 + v9 )
  {
    v7 = v4 + 1;
    v8 = v7;
    v9 = v7 + 2;
    v10 = (unsigned __int8)v3[v8 + 1] + ((unsigned __int8)v3[v8] << 8);
    if ( v5 )
      CertAddEncodedCertificateToStore(i, 1u, &v3[v9], v10, 4u, 0i64);
    else
      v5 = CertCreateCertificateContext(1u, &v3[v9], v10);
  }
  pChainContext = 0i64;
  v20 = "1.3.6.1.5.5.7.3.1";
  *(_QWORD *)&pChainPara.RequestedUsage.dwType = 0i64;
  *(_QWORD *)&pChainPara.RequestedUsage.Usage.cUsageIdentifier = 0i64;
  pChainPara.RequestedUsage.Usage.rgpszUsageIdentifier = (char **)&v20;
  pChainPara.cbSize = 32;
  pChainPara.RequestedUsage.Usage.cUsageIdentifier = 1;
  CertGetCertificateChain(0i64, v5, 0i64, i, &pChainPara, 0x20000000u, 0i64, &pChainContext);
  v16 = 24;
  memset(&Dst, 0, 0x14ui64);
  v18 = byte_1416A7BD8;
  Dst = 2;
  *(_QWORD *)&pPolicyPara.cbSize = 16i64;
  pPolicyStatus.cbSize = 24;
  pPolicyPara.pvExtraPolicyPara = &v16;
  memset(&pPolicyStatus.dwError, 0, 0x14ui64);
  v11 = CertVerifyCertificateChainPolicy((LPCSTR)4, pChainContext, &pPolicyPara, &pPolicyStatus);
  if ( pChainContext )
    CertFreeCertificateChain(pChainContext);
  if ( v5 )
    CertFreeCertificateContext(v5);
  return v11;
}

