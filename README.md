# rayTracingAlgorithms

## Linha do Tempo

1. **Pré-ray tracing moderno**
   - **Ray Casting (1968)**
     - Arthur Appel
     - Apenas visibilidade (sem iluminação global)
     - Ray casting algorithm that used for rendering was first introduced by Arthur Appel in 1968. Ray casting renders the scene by emitting a ray from the observation point to each pixel and finding the closest object that blocks the light path in the world scene. Only two rays were involved in ray casting. The first emitted by the eye to find the intersection point, the other was sent from the intersection point to the light, to see if the ray itself is in the shadow.
     - <img width="1148" height="615" alt="img/Intuition_of_Ray_casting" src="https://github.com/user-attachments/assets/6b895d14-2785-420a-b306-9f33f45f492e" />
     - The facets are oriented using the right-hand rule: the vertices are listed in counter-clockwise order when looking at the object from the outside. In other words, for a given facet ABC, the normal vector n = AB · AC is out-ward. We use the notation AB to denote the vector from A to B.

     - Fontes:
        - <https://ceur-ws.org/Vol-3150/short3.pdf> 
           @inproceedings{wang2022development,
              title={The Development of Ray Tracing and Its Future.},
              author={Wang, Zijin},
              booktitle={CONF-SPML},
              pages={19--28},
              year={2022}
            }
        - <https://www.sciencedirect.com/science/article/pii/S0168583X0600245X?casa_token=wnG_kDe1ByAAAAAA:ZrzHlauIb-ZUv24h2AVP4oeqgg3Fcd6PJeNWSuYH42z3sCA4Ftn_GlYQ-O5y17LykjMhxXauXiLAjg>
           @article{freud2006fast,
              title={Fast and robust ray casting algorithms for virtual X-ray imaging},
              author={Freud, Nicolas and Duvauchelle, Philippe and L{\'e}tang, Jean-Michel and Babot, Daniel},
              journal={Nuclear Instruments and Methods in Physics Research Section B: Beam Interactions with Materials and Atoms},
              volume={248},
              number={1},
              pages={175--180},
              year={2006},
              publisher={Elsevier}
            }

2. **Ray tracing clássico**
   - **Whitted Ray Tracing (1980)**
     - Turner Whitted
     - Reflexão, refração, sombras
     - Ainda determinístico
     - Base física (rendering equation)
     - Pioneered by the works of Whitted and Appel, ray tracing has become a standard format for image rendering. Ray tracing is a very accurate mathematical calculation of light and color, but is a very slow process
     - Beyond primary visibility, Whitted ray tracing requires secondary rays for point-light shadows, reflections, and refractions. According to "E. Mansson, J. Munkberg, and T. Akenine-Moller. Deep coherent ray tracing. IEEE Symp. on Interactive Ray Tracing, 2007", ray coherence degrades for these secondary effects, and we expect a corresponding drop in performance for large ray packet algorithms.
     - Specular reflections is one area where ray-traced images typically differ from images generated with rasterization. These effects depend on secondary rays, as opposed to the primary rays (rays originating from the viewpoint of the camera). Secondary rays include reflected rays (after one or several reflections), refracted rays and shadow rays. While primary rays are highly coherent, making it easier to optimize the computations, e.g. using caching schemes together with the scene hierarchies, secondary rays exhibit much less coherence: two secondary rays generated from neighbouring points can intersect with objects that are far away in the scene. As a consequence, efficient computation of secondary rays is a harder problem than for primary rays.
     - <img width="1070" height="609" alt="Illustration of rays, vectors and angles required in ray tracing" src="https://github.com/user-attachments/assets/6747cf25-97f4-40ca-8507-c31126736bdf" />

    
      - <http://www.billmark.com/papers/whitted.pdf>
         @inproceedings{overbeck2008large,
            title={Large ray packets for real-time whitted ray tracing},
            author={Overbeck, Ryan and Ramamoorthi, Ravi and Mark, William R},
            booktitle={2008 IEEE Symposium on Interactive Ray Tracing},
            pages={41--48},
            year={2008},
            organization={IEEE}
         }

     - Fonte:
        - <https://docs.lib.purdue.edu/cgi/viewcontent.cgi?article=1024&context=techmasters>
        - <https://inria.hal.science/hal-00171587/document>
           @inproceedings{roger2007whitted,
              title={Whitted ray-tracing for dynamic scenes using a ray-space hierarchy on the GPU},
              author={Roger, David and Assarsson, Ulf and Holzschuch, Nicolas},
              booktitle={Symposium on Rendering, Rendering Techniques 2007},
              pages={99--110},
              year={2007},
              organization={Eurographics Association}
            }

        - <http://www.billmark.com/papers/whitted.pdf>
         @inproceedings{overbeck2008large,
            title={Large ray packets for real-time whitted ray tracing},
            author={Overbeck, Ryan and Ramamoorthi, Ravi and Mark, William R},
            booktitle={2008 IEEE Symposium on Interactive Ray Tracing},
            pages={41--48},
            year={2008},
            organization={IEEE}
         }

   - **Path Tracing (1986)**
     - James Kajiya
     - Introduz Monte Carlo
     - Simulação física completa da luz
     - Kajiya presented the rendering equation and intro duced path tracing as a Monte Carlo algorithm to solve it The idea is to sample the ux through the pixels gathering light by following all light paths back to the light sources As such it is entirely view dep endent Various other algorithms are based on the same principle. Monte Carlo techniques are capable of handling the most general class of lighting effects but are generally slow to converge
     - Global illumination algorithms seek to estimate the value of each image pixel defined as a complex integral over the space of light paths, relying on large numbers of Monte-Carlo samples to avoid noise. Recent advances
    
     - Fonte
        - <https://masters.donntu.ru/2013/fknt/kalamitra/library/Bidirectional%20Path%20Tracing%201990.pdf>
           @article{lafortune1993bi,
              title={Bi-directional path tracing},
              author={Lafortune, Eric P and Willems, Yves D},
              year={1993}
            }
        - 

3. **Expansões Monte Carlo (anos 90**
   - **Bidirectional Path Tracing (BDPT)**
     - Conecta câmera ↔ luz
     - Melhor em cenas difíceis
     - Most current global illumination algorithms ignore the influence of the medium through which the light travels. In these illumination simulations, light is only emitted and re-flected at surfaces; the absorption, scattering and emission of light as a result of smoke, dust, fog or flames are neglected.
     - Depending on the applications they handle homogeneous or non-homogeneous and isotropic or anisotropic media
     - Bidirectional path tracing combines the ideas of path tracing and light tracing by creating random walks, starting not only from the eye point, but also from the light sources. Eye paths start from the eye point, through the pixel that is being computed, as in classical path tracing. Light paths start from a sampled point on a light source in a sampled direction. Rays can be scattered or absorbed in the medium, as well as being reflected or absorbed at the surfaces of the scene.
     - After tracing a pair of random walks, the intersection points on the respective paths are connected by means of shadow rays. Each shadow ray that is not intercepted by an object in the scene contributes to the estimated flux or average radiance through the pixel.
     - <img width="802" height="568" alt="Bidirectional Path Tracing" src="https://github.com/user-attachments/assets/8008f47b-02af-4703-af1d-99eac6a44ab7" />
     - Fontes:
        - <http://luthuli.cs.uiuc.edu/~daf/courses/rendering/papers/lafortune96rendering.pdf>
        @inproceedings{lafortune1996rendering,
           title={Rendering participating media with bidirectional path tracing},
           author={Lafortune, Eric P and Willems, Yves D},
           booktitle={Eurographics Workshop on Rendering Techniques},
           pages={91--100},
           year={1996},
           organization={Springer}
         }


   - **Metropolis Light Transport (MLT)**
     - Eric Veach
     - Amostragem baseada em mutações
     - Excelente para iluminação complexa
     - A Monte Carlo method for solving the light transport problem, inspired by the Metropolis sampling method in computational physics. To render an image, we generate a sequence of light transport paths by randomly mutating a single current path
     - Each mutation is accepted or rejected with a care-fully chosen probability, to ensure that paths are sampled according to the contribution they make to the ideal image. We then estimate this image by sampling many paths, and recording their locations on the image plane.
     - The key advantage of the Metropolis approach is that the path space is explored locally, by favoring mutations that make small changes to the current path. This has several consequences. First, the average cost per sample is small (typically only one or two rays). Second, once an important path is found, the nearby paths are explored as well, thus amortizing the expense of finding such paths over many samples. Third, the mutation set is easily extended. By constructing mutations that preserve certain properties of the path (e.g. which light source is used) while changing others, we can exploit various kinds of coherence in the scene. It is often possible to handle difficult lighting problems efficiently by designing a specialized mutation in this way.
     - <img width="670" height="376" alt="Metropolis light transport" src="https://github.com/user-attachments/assets/dff27d04-2f03-417a-b5dc-6970209e2f49" />
     - <img width="844" height="384" alt="Metropolis light transport" src="https://github.com/user-attachments/assets/33480741-c140-48e9-ab3e-ac98f83f7635" />

     - Fonte:
        - <https://dl.acm.org/doi/pdf/10.1145/258734.258775>
           @inproceedings{veach1997metropolis,
              title={Metropolis light transport},
              author={Veach, Eric and Guibas, Leonidas J},
              booktitle={Proceedings of the 24th annual conference on Computer graphics and interactive techniques},
              pages={65--76},
              year={1997}
            }
         - <https://www.semanticscholar.org/topic/Metropolis-light-transport/1141468>

   - **Light Tracing**
     - Raios partem da luz (não da câmera)
     - existe porem n achei artigo relacionado

   - **Photon Mapping**
      - Henrik Wann Jensen
      - Dois passos:
          1. Emissão de fótons
          2. Reconstrução da iluminação
      - Photon Mapping is a two-pass algorithm. The first pass is photon tracing, which traces photons from the light sources into the scene and stores them in a photon map as they interact with the surfaces
      - The second pass is rendering in which the photon map is used to estimate the illumination in the scene.
      - In the ray tracing pass the photon map is used to estimate the radiance at different locations within the scene. This is done by locating the nearest photons and performing a nearest neighbor density estimation. Since the density estimation process can be considered as a way of loosely connecting paths from the eye to the light, photon mapping is very effective at rendering SDS paths. The density estimation process effectively blurs the lighting in the scene, and to represent sharp illumination details it is necessary to use a large number of photons.
      - A simple and robust progressive global illumination algorithm based on photon mapping. Progressive photon mapping is a multi-pass algorithm where the first pass is ray tracing followed by any number of photon tracing passes. Each photon tracing pass results in an increasingly accurate global illumination solution that can be visualized in order to provide progressive feedback. Progressive photon mapping uses a new radiance estimate that converges to the correct radiance value as more photons are used. It is not necessary to store the full photon map, and unlike standard photon mapping it possible to compute a global illumination solution with any desired accuracy using a limited amount of memory. Compared with existing Monte Carlo ray tracing methods progressive photon mapping provides an efficient and robust alternative in the presence of complex light transport such as caustics and in particular reflections of caustics.
      - <img width="408" height="540" alt="image" src="https://github.com/user-attachments/assets/56485068-a709-4cef-b63f-b73583a2bc14" />

      -  Fonte:
         -  <https://dl.acm.org/doi/pdf/10.1145/1457515.1409083>
            @incollection{hachisuka2008progressive,
              title={Progressive photon mapping},
              author={Hachisuka, Toshiya and Ogaki, Shinji and Jensen, Henrik Wann},
              booktitle={ACM SIGGRAPH Asia 2008 papers},
              pages={1--8},
              year={2008}
           }
      -  https://people.eecs.berkeley.edu/~sequin/CS184/TOPICS/GlobalIllumination/Gill_b.html

4. **Métodos híbridos (2000+)**
   - **Instant Radiosity**
     - Aproxima iluminação global com luzes virtuais
     - Generates a particle approximation of the diffuse radiance in the scene using the quasi-random walk [Kel96b] based on the method of quasi-Monte Carlo integration. Then the graphics hardware renders an image with shadows for each particle used as point light source. Global illumination finally is obtained by summing up the single images in an accumulation buffer [HA90] and displaying the result. The algorithm calculates the average radiance
     - combine the advantages of deterministic particle simulation of light, i.e. the quasi-random walk principle, with the available hardware capabilities to consistently render from the radiance equation, neither using a kernel nor an intermediate solution projection of the integral equation, resulting in a very fast, robust and straightforward to implement procedure.
     - Instant radiosity [Kel97] and its variants form one category. These methods construct (quasi-)random paths from the light sources and deposit virtual point lights (VPLs) at the vertices of the paths. When used together with a suitable shadow solver, usually shadow maps, these point lights represent the full indirect illumination in the scene. Instant radiosity techniques are GPU-friendly due to the fact that most of the computation is spent on per-pixel lighting
     - <img width="774" height="395" alt="Instant Radiosity" src="https://github.com/user-attachments/assets/1849a679-eb82-408f-b943-cd278151e74e" />

    
     - Fonte:
        - <https://dl.acm.org/doi/pdf/10.1145/258734.258769>
           @inproceedings{keller1997instant,
              title={Instant radiosity},
              author={Keller, Alexander},
              booktitle={Proceedings of the 24th annual conference on Computer graphics and interactive techniques},
              pages={49--56},
              year={1997}
            }
        - <https://www.nvidia.com/docs/io/67074/laine2007egsr_paper.pdf>
           @inproceedings{laine2007incremental,
              title={Incremental Instant Radiosity for Real-Time Indirect Illumination.},
              author={Laine, Samuli and Saransaari, Hannu and Kontkanen, Janne and Lehtinen, Jaakko and Aila, Timo},
              booktitle={Rendering Techniques},
              pages={277--286},
              year={2007}
            }

   - **Final Gathering**
     - Refinamento de iluminação indireta
     - The method proposed here uses a randomly sampled global ray direction [Szirmay-Kalos 1998]. Using this direction, expensive ray intersection can be regarded as a multi-layered parallel projection (see Figure 1). Since graphics hardware can process matrix transformation including parallel projection very fast, such a method is natural and efficient compared with using GPU as a parallel ray tracing processor. Intersection points of global ray direction from sampling points cannot be obtained by single parallel projection, so inverse of depth peeling [Everitt 2001] is used instead to get actual intersection points. Each depth layer is projected from far to near and intersection points sample nearest depth layer. Depth layer texel behind the intersection point is culled by a KILL operation. To reduce the number of depth peeling iterations, criteria based on the number of sampled points can be used to stop the iteration without significant error on resulting image. Since the proposed method is per-pixel, it can process any form of problem that requires a large number of samples on hemisphere such as pre-computation of radiance transfer. To apply this method to a global illumination problem, some pre-computed rough global illumination solution of the scene is needed so I use grid photon map as a pre-process in the demo.
     - <img width="606" height="298" alt="Final Gathering" src="https://github.com/user-attachments/assets/e30b5d8f-9e64-483e-9615-51cbfa0f85ee" />
     - Fonte:
        - <https://cs.uwaterloo.ca/~thachisu/gpufg.pdf>
           @inproceedings{hachisuka2004final,
              title={Final gathering on GPU},
              author={Hachisuka, Toshiya},
              booktitle={ACM Workshop on General Purpose Computing on Graphics Processors},
              volume={3},
              year={2004}
            }


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
