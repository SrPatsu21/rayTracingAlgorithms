# rayTracingAlgorithms

## Linha do tempo:
Pré-ray tracing moderno
Ray Casting (1968)
Arthur Appel
Apenas visibilidade (sem iluminação global)
 2. Ray tracing clássico
Whitted Ray Tracing (1980)
Turner Whitted
Reflexão, refração, sombras
Ainda determinístico
Base física (rendering equation)
Path Tracing (1986)
James Kajiya
Introduz Monte Carlo
Simulação física completa da luz
Expansões Monte Carlo (anos 90)
Bidirectional Path Tracing (BDPT)
Conecta câmera ↔ luz
Melhor em cenas difíceis
Metropolis Light Transport (MLT)
Eric Veach
Amostragem baseada em mutações
Excelente para iluminação complexa
Light Tracing
Raios partem da luz (não da câmera)
Photon Mapping
Henrik Wann Jensen
Dois passos:
emissão de fótons
reconstrução da iluminação
 Métodos híbridos (2000+)
Instant Radiosity
Aproxima iluminação global com luzes virtuais
Final Gathering
Refinamento de iluminação indireta
Distributed Ray Tracing
Amostragem para:
motion blur
depth of field
soft shadows
Técnicas modernas (2010+)
Progressive Path Tracing
Refinamento progressivo da imagem
Vertex Connection and Merging (VCM)
Combina BDPT + Photon Mapping
Unified Path Sampling
Unifica vários métodos Monte Carlo
Energy Redistribution Path Tracing (ERPT)
Variante do MLT
 Estado da arte atual (2018+)
ReSTIR (Reservoir-based Spatiotemporal Importance Resampling)
Reutiliza amostras entre pixels/frames
Muito usado em tempo real
ReSTIR GI
Extensão para iluminação global
Neural Path Tracing
Usa redes neurais para:
denoising
amostragem
Differentiable Ray Tracing
Permite otimização (usado em ML)
