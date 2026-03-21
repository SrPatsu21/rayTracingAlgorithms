# rayTracingAlgorithms

## Linha do Tempo

1. **Pré-ray tracing moderno**
   - **Ray Casting (1968)**
     - Arthur Appel
     - Apenas visibilidade (sem iluminação global)
     - Ray casting algorithm that used for rendering was first introduced by Arthur Appel in 1968. Ray casting renders the scene by emitting a ray from the observation point to each pixel and finding the closest object that blocks the light path in the world scene. Only two rays were involved in ray casting. The first emitted by the eye to find the intersection point, the other was sent from the intersection point to the light, to see if the ray itself is in the shadow.
     - <img width="1148" height="615" alt="img/Intuition_of_Ray_casting" src="https://github.com/user-attachments/assets/6b895d14-2785-420a-b306-9f33f45f492e" />

     - Fontes:
        - <https://ceur-ws.org/Vol-3150/short3.pdf> 
           @inproceedings{wang2022development,
              title={The Development of Ray Tracing and Its Future.},
              author={Wang, Zijin},
              booktitle={CONF-SPML},
              pages={19--28},
              year={2022}
            }

2. **Ray tracing clássico**
   - **Whitted Ray Tracing (1980)**
     - Turner Whitted
     - Reflexão, refração, sombras
     - Ainda determinístico
     - Base física (rendering equation)
     - Fonte:
        - <https://docs.lib.purdue.edu/cgi/viewcontent.cgi?article=1024&context=techmasters>

   - **Path Tracing (1986)**
     - James Kajiya
     - Introduz Monte Carlo
     - Simulação física completa da luz

3. **Expansões Monte Carlo (anos 90**
   - **Bidirectional Path Tracing (BDPT)**
     - Conecta câmera ↔ luz
     - Melhor em cenas difíceis

   - **Metropolis Light Transport (MLT)**
     - Eric Veach
     - Amostragem baseada em mutações
     - Excelente para iluminação complexa

   - **Light Tracing**
     - Raios partem da luz (não da câmera)

   - **Photon Mapping**
     - Henrik Wann Jensen
     - Dois passos:
       1. Emissão de fótons
       2. Reconstrução da iluminação

4. **Métodos híbridos (2000+)**
   - **Instant Radiosity**
     - Aproxima iluminação global com luzes virtuais

   - **Final Gathering**
     - Refinamento de iluminação indireta

   - **Distributed Ray Tracing**
     - Amostragem para:
       - Motion blur
       - Depth of field
       - Soft shadows

5. **Técnicas modernas (2010+)**
   - **Progressive Path Tracing**
     - Refinamento progressivo da imagem

   - **Vertex Connection and Merging (VCM)**
     - Combina BDPT + Photon Mapping

   - **Unified Path Sampling**
     - Unifica vários métodos Monte Carlo

   - **Energy Redistribution Path Tracing (ERPT)**
     - Variante do MLT

6. **Estado da arte atual (2018+)**
   - **ReSTIR (Reservoir-based Spatiotemporal Importance Resampling)**
     - Reutiliza amostras entre pixels/frames
     - Muito usado em tempo real

   - **ReSTIR GI**
     - Extensão para iluminação global

   - **Neural Path Tracing**
     - Usa redes neurais para:
       - Denoising
       - Amostragem

   - **Differentiable Ray Tracing**
     - Permite otimização (usado em ML)

- **Fontes:**
   - <https://ceur-ws.org/Vol-3150/short3.pdf>

## Estruturas de aceleração:
1. **Clássicas**

   - **BVH (Bounding Volume Hierarchy)**
     - Mais usado hoje
     - Variações:
       - SAH BVH
       - LBVH (GPU)
       - HLBVH
   - **KD-Tree**
     - Muito eficiente, mas caro de construir
   - **Uniform Grid**
     - Simples
     - Ruim em cenas não uniformes
   - **Octree**
     - Divisão recursiva do espaço

2. **Intermediárias**

   - **BSP Tree (Binary Space Partitioning)**
     - Generalização do KD-tree
   - **Bounding Interval Hierarchy (BIH)**
     - Mais simples que BVH
   - **Grid Hierárquico**
     - Combinação de grids

3. **Modernas / GPU**

   - **Linear BVH (LBVH)**
     - Construção rápida em GPU
   - **Hierarchical LBVH (HLBVH)**
     - Combina qualidade + velocidade
   - **Wide BVH (BVH4, BVH8)**
     - Melhor uso de SIMD
   - **Compressed BVH**
     - Reduz memória

## Técnicas de Amostragem

   - **Importance Sampling**
   - **Multiple Importance Sampling (MIS)**
   - **Stratified Sampling**
   - **Blue Noise Sampling**

## O que comparar

   - **Tempo de construção**
   - **Tempo de travessia**
   - **Uso de memória**
   - **throughput (rays/sec)**
   - **escalabilidade**
   - **eficiência energética**

## Técnicas de redução de ruído
   - **Denoising clássico**
   - **Spatiotemporal filtering**
   - **AI denoising**
