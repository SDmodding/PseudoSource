// File Line: 12
// RVA: 0xEF53C0
__int64 __fastcall ssl_verify_cert_win(const char *buffer, int bufferSize)
{
  int v4; // ebx
  _CERT_CONTEXT *CertificateContext; // rsi
  HCERTSTORE i; // r12
  int v7; // ebx
  __int64 v8; // rcx
  int v9; // ebx
  DWORD v10; // edi
  unsigned int v11; // ebx
  PCCERT_CHAIN_CONTEXT pChainContext; // [rsp+40h] [rbp-49h] BYREF
  _CERT_CHAIN_POLICY_PARA pPolicyPara; // [rsp+48h] [rbp-41h] BYREF
  _CERT_CHAIN_PARA pChainPara; // [rsp+58h] [rbp-31h] BYREF
  _BYTE v16[24]; // [rsp+78h] [rbp-11h] BYREF
  _CERT_CHAIN_POLICY_STATUS pPolicyStatus; // [rsp+90h] [rbp+7h] BYREF
  const char *v18; // [rsp+A8h] [rbp+1Fh] BYREF

  v4 = 0;
  CertificateContext = 0i64;
  for ( i = CertOpenStore((LPCSTR)2, 0, 0i64, 0, 0i64); v4 < bufferSize; v4 = v10 + v9 )
  {
    v7 = v4 + 1;
    v8 = v7;
    v9 = v7 + 2;
    v10 = (unsigned __int8)buffer[v8 + 1] + ((unsigned __int8)buffer[v8] << 8);
    if ( CertificateContext )
      CertAddEncodedCertificateToStore(i, 1u, &buffer[v9], v10, 4u, 0i64);
    else
      CertificateContext = CertCreateCertificateContext(1u, &buffer[v9], v10);
  }
  pChainContext = 0i64;
  v18 = "1.3.6.1.5.5.7.3.1";
  *(_QWORD *)&pChainPara.RequestedUsage.dwType = 0i64;
  *(&pChainPara.RequestedUsage.Usage.cUsageIdentifier + 1) = 0;
  pChainPara.RequestedUsage.Usage.rgpszUsageIdentifier = (char **)&v18;
  pChainPara.cbSize = 32;
  pChainPara.RequestedUsage.Usage.cUsageIdentifier = 1;
  CertGetCertificateChain(0i64, CertificateContext, 0i64, i, &pChainPara, 0x20000000u, 0i64, &pChainContext);
  memset(&v16[4], 0, 0x14ui64);
  *(_QWORD *)&v16[16] = byte_1416A7BD8;
  *(_QWORD *)v16 = 0x200000018i64;
  *(_QWORD *)&pPolicyPara.cbSize = 16i64;
  pPolicyStatus.cbSize = 24;
  pPolicyPara.pvExtraPolicyPara = v16;
  memset(&pPolicyStatus.dwError, 0, 0x14ui64);
  v11 = CertVerifyCertificateChainPolicy((LPCSTR)4, pChainContext, &pPolicyPara, &pPolicyStatus);
  if ( pChainContext )
    CertFreeCertificateChain(pChainContext);
  if ( CertificateContext )
    CertFreeCertificateContext(CertificateContext);
  return v11;
}

