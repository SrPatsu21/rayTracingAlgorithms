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
    - Distributed ray tracing is a new approach to image synthesis. The key is that no extra rays are needed beyond those used for oversampling in space. For example,
rather than taking multiple time samples at every spatial location, the rays are distributed in time so that rays at different spatial locations are traced at different instants of time.
    - Once we accept the expense of oversampling in space, distributing the rays offers substantial benefits at little additional cost.
       - Sampling the reflected ray according to the specular distribution function produces gloss (blurred reflection).
       - Sampling the transmitted ray produces translucency (blurred transparency).
       - Sampling the solid angle of the light sources produces penumbras.
       - Sampling the camera lens area produces depth of field.
       - Sampling in time produces motion blur.
    - Distribution ray tracing uses Monte Carlo integration to solve the rendering equation. This technique was intro duced by Co ok et. al, and was notable b ecause of its simplicity and its ability to simulate areal luminaires, camera lens e ects, motion blur, and imp erfect sp ecular re ection[5]. Distribution ray tracing has b een extended and mo di ed by many researchers, most notably by Ka jiya who added true indirect illumination[12]. Distribution ray tracing has also b een used as the viewing comp onent of radiosity systems

    - <img width="528" height="231" alt="Distributed Ray Tracing" src="https://github.com/user-attachments/assets/adaff941-2ea0-43eb-b9e4-1c976d17d1e6" />
    - <img width="528" height="260" alt="Distributed Ray Tracing" src="https://github.com/user-attachments/assets/54e01c92-b129-442f-beee-2d495169b6af" />


    - Font:
    - <https://dl.acm.org/doi/pdf/10.1145/800031.808590>
       @inproceedings{cook1984distributed,
           title={Distributed ray tracing},
           author={Cook, Robert L and Porter, Thomas and Carpenter, Loren},
           booktitle={Proceedings of the 11th annual conference on Computer graphics and interactive techniques},
           pages={137--145},
           year={1984}
         }
    - <https://www.researchgate.net/profile/Peter-Shirley-2/publication/2600519_Distribution_Ray_Tracing_Theory_and_Practice/links/0046351ded394e888d000000/Distribution-Ray-Tracing-Theory-and-Practice.pdf>
       @inproceedings{shirley1992distribution,
        title={Distribution ray tracing: Theory and practice},
        author={Shirley, Peter and Wang, Changyaw},
        booktitle={Proceedings of the Third Eurographics Workshop on Rendering},
        pages={200--209},
        year={1992}
      }


5. **Técnicas modernas (2010+)**
   - **Progressive Path Tracing**
     - Refinamento progressivo da imagem
     - designed an improved bilateral filtering algorithm with use of the gradient feature to obtain the noise-free images. Experimental results demonstrate that our framework outperforms the state-of-the-art path tracing denoising methods in terms of the visual quality, numerical error , and time cost.
     -  A real-time previsualization framework is presented, which renders the solution with a low number of samples during interaction and allows for progressive quality improvement. If a user requests the high-quality solution of a certain view, the tracking is stopped and the algorithm progressively converges to an accurate solution.
     - Fonte:
     - <https://link.springer.com/article/10.1007/s11042-020-09650-7>
        @article{xing2021progressive,
           title={Progressive path tracing with bilateral-filtering-based denoising},
           author={Xing, Qiwei and Chen, Chunyi and Li, Zhihua},
           journal={Multimedia Tools and Applications},
           volume={80},
           number={1},
           pages={1529--1544},
           year={2021},
           publisher={Springer}
         }
     - <http://peterkan.com/download/isvc.pdf>
        @inproceedings{kan2013differential,
           title={Differential progressive path tracing for high-quality previsualization and relighting in augmented reality},
           author={K{\'a}n, Peter and Kaufmann, Hannes},
           booktitle={International Symposium on Visual Computing},
           pages={328--338},
           year={2013},
           organization={Springer}
         }

   - **Vertex Connection and Merging (VCM)**
     - Combina BDPT + Photon Mapping
     - Bidirectional path tracing (BPT) and photon mapping (PM) are probably the two most versatile physically based rendering algorithms available today. It has been acknowledged that BPT and PM are complementary in terms of the types of light transport effects they can efficiently capture. Our recently proposed vertex connection and merging (VCM) algorithm aims to leverage the advantages of both methods by combining vertex connection techniques from BPT and vertex merging techniques from PM via multiple importance sampling
     - <img width="1165" height="627" alt="image" src="https://github.com/user-attachments/assets/f52f4b49-8b21-4f5b-8753-a1186e78be7b" />
     - Fonte
        - <http://iliyan.com/publications/ImplementingVCM/ImplementingVCM_TechRep2012_rev2.pdf>
           @article{georgiev2012implementing,
              title={Implementing vertex connection and merging},
              author={Georgiev, Iliyan},
              journal={Technical Re-port. Saarland University},
              year={2012}
            }
        - 

   - **Unified Path Sampling**
     - Unifica vários métodos Monte Carlo

   - **Energy Redistribution Path Tracing (ERPT)**
     - Variante do MLT

6. **Estado da arte atual (2018+)**
   - **ReSTIR (Reservoir-based Spatiotemporal Importance Resampling) && ReSTIR GI (Extensão para iluminação global)**
     - Reutiliza amostras entre pixels/frames
     - Muito usado em tempo real
     - The original ReSTIR algorithm [BWP∗20] places initial samples using light sampling where the source PDF p(x) samples uniformly on the surfaces of lights that are themselves sampled according to their emitted power. The target function p̂(x) is then given by the unshadowed reflected radiance due to the light sample, which is given by the product of emitted radiance, the BSDF, and the geometric coupling term.
     - To apply ReSTIR to sample indirect illumination, we must represent directions that contribute to indirect illumination. Because this representation must support both spatial and temporal reuse at different points in space, unit vectors on the local hemisphere of directions are an inconvenient representation. We therefore associate points on surfaces with the radiance they scatter back along an incident ray.
     - We will say that the visible points are the positions on surfaces in the scene that are visible from the camera at each pixel. At each visible point, a direction is randomly sampled and a ray is traced to find the closest surface intersection; these intersections are called sample points. Sample generation is described in more detail in Section 4.1. After sample points have been generated, resampling is performed and shaded values are computed at each visible point (Section 4.2). Figure 2 compares ReSTIR for direct lighting to ReSTIR GI and Figure 4 summarizes the algorithm.
     - Original ReSTIR and ReSTIR GI. (a) The original ReSTIR algorithm [BWP∗20] starts by generating random samples on the lights in the scene. (b) After resampling, the original samples with no contribution are discarded; the useful samples are shared spatially and temporally and are used with probability based on their contribution. (c) Our approach generates initial samples by sampling random directions and tracing rays to find the closest intersections. Reflected radiance is computed at these intersections with path tracing. (d) Spatial and temporal resampling is applied in a similar manner. Doing so makes it possible to find directions that give meaningful indirect illumination, which is not handled by ReSTIR.
     - <img width="1353" height="334" alt="image" src="https://github.com/user-attachments/assets/cd303014-c144-40c7-8e54-f8fecb326444" />
     - Fonte
        - <https://onlinelibrary.wiley.com/doi/full/10.1111/cgf.14378?casa_token=l_hjR-IIzaAAAAAA%3AG8y5HCiHoLmvkbxpdOM1G8kCeGX6bie-PwggzKpQ0Z3g_FBHZLImK70sUtsBh5ybGVuw-I63ZweG37LtTw>
        @inproceedings{ouyang2021restir,
           title={ReSTIR GI: Path resampling for real-time path tracing},
           author={Ouyang, Yaobin and Liu, Shiqiu and Kettunen, Markus and Pharr, Matt and Pantaleoni, Jacopo},
           booktitle={Computer graphics forum},
           volume={40},
           number={8},
           pages={17--29},
           year={2021},
           organization={Wiley Online Library}
         }

   - **Neural Path Tracing**
     - Usa redes neurais para:
       - Denoising
       - Amostragem
       - Rendering a single frame consists of computing pixel colors and updating the neural radiance cache; see Figure 2 for an illustration. First, we trace short rendering paths, one for each pixel, and terminate them as soon as the approximation provided by the radi ance cache is deemed sufficiently accurate. We use the heuristic by Bekaert et al . [2003], that was originally developed in the context of
       - For rendering, we trace short “rendering” paths (e.g. x0 · · · x2) and terminate them into the neural radiance cache; queries of cached radiance b𝐿s are highlighted by red arrows. To optimize the cache, we extend a small subset of the rendering paths by a few vertices (called “training suffix”, e.g. y2 · · · y4). We collect radiance estimates (blue arrows) to update the neural radiance cache along the vertices of the longer training path, reusing the initial path segment that was already traced for rendering. Furthermore, the online training together with the termination of training paths into the cache progressively increases the number of simulated light bounces.
       - <img width="637" height="234" alt="image" src="https://github.com/user-attachments/assets/30334c09-6aa3-480d-a20e-7d629883d229" />
       - Fonte
       - <https://arxiv.org/pdf/2106.12372>
          @article{muller2021real,
              title={Real-time neural radiance caching for path tracing},
              author={M{\"u}ller, Thomas and Rousselle, Fabrice and Nov{\'a}k, Jan and Keller, Alexander},
              journal={arXiv preprint arXiv:2106.12372},
              year={2021}
            }

   - **Differentiable Ray Tracing**
     - Permite otimização (usado em ML)
     - a general-purpose differentiable ray tracer, which, to our knowledge, is the first comprehensive solution that is able to compute derivatives of scalar functions over a rendered image with respect to arbitrary scene parameters such as camera pose, scene geometry, materials, and lighting parameters.
     - The key to our method is a novel edge sampling algorithm that directly samples the Dirac delta functions introduced by the derivatives of the discontinuous integrand. We also develop efficient importance sampling methods based on spatial hierarchies. Our method can generate gradients in times running from seconds to minutes depending on scene complexity and desired precision. We interface our differentiable ray tracer with the deep learning library PyTorch and show prototype applications in inverse rendering and the generation of adversarial examples for neural networks.
     - Our task is the following: given a 3D scene with a continuous parameter set Φ (including camera pose, scene geometry, material and lighting parameters), we generate an image using the path tracing algorithm [Kajiya 1986]. Given a scalar function computed from the image (e.g. a loss function we want to optimize), our goal is to backpropagate the gradient of the scalar with respect to all scene parameters Φ.
     - The pixel color is formalized as an integration over all light paths that pass through the pixel filter. We use Monte Carlo sampling to estimate both the integral and the gradient of the integral. However, since the integrand is discontinuous due to edges of geometry and occlusion, traditional area sampling does not correctly capture the changes due to camera parameters or triangle vertex movement (Figure 2 (a)). Mathematically, the gradient of the discontinuous integrand is a Dirac delta function, therefore traditional sampling has zero probability of capturing the Dirac deltas.
     - Our strategy for computing the gradient integral is to split it into smooth and discontinuous regions (Figure 2). For the smooth part of the integrand (e.g. Phong shading or bilinear texture reconstruction) we employ traditional area sampling with automatic differentiation. For the discontinuous part we use a novel edge sampling method to capture the changes at boundaries. In the following subsection, we first focus on primary visibility where we only integrate over the 2D screen-space domain (Section 3.1). We then generalize the method to handle shadow and global illumination
     - <img width="725" height="691" alt="image" src="https://github.com/user-attachments/assets/79e166a0-762b-4fd4-b6f5-80375c845f0a" />

- **Fontes:**
   - <ttps://dl.acm.org/doi/pdf/10.1145/3272127.3275109>
   @article{li2018differentiable,
     title={Differentiable monte carlo ray tracing through edge sampling},
     author={Li, Tzu-Mao and Aittala, Miika and Durand, Fr{\'e}do and Lehtinen, Jaakko},
     journal={ACM Transactions on Graphics (TOG)},
     volume={37},
     number={6},
     pages={1--11},
     year={2018},
     publisher={ACM New York, NY, USA}
   }

## Estruturas de aceleração:
1. **Clássicas**

   - **BVH (Bounding Volume Hierarchy)**
     - Mais usado hoje
     - Variações:
       - SAH BVH
       - LBVH (GPU)
       - HLBVH
       - Bounding volume hierarchies (BVH) are a commonly used method for speeding up ray tracing. Even though the memory footprint of a BVH is relatively low compared to other acceleration data structures, they still can consume a large amount of memory for complex scenes and exceed the memory bounds of the host system
       - The idea behind a BVH is to subdivide the primitives of a scene into possibly overlapping sets.
       - For each of these sets a bounding volume (BV) is computed and these are arranged in a tree structure. The bounds of every node in this tree are chosen so that it exactly bounds all the nodes in the corresponding subtree and every leaf node exactly bounds the contained primitives. Ray traversal then starts at the root node and if a ray misses a BV in this hierarchy, the whole subtree can be skipped.
       - <img width="1024" height="768" alt="image" src="https://github.com/user-attachments/assets/af11677b-764e-473f-9df7-96ed145ff82d" />

       - Fonte:
          - <https://diglib.eg.org/server/api/core/bitstreams/68ca5e89-763a-4254-b498-245009148c62/content>
             @inproceedings{bauszat2010minimal,
                 title={The Minimal Bounding Volume Hierarchy.},
                 author={Bauszat, Pablo and Eisemann, Martin and Magnor, Marcus A},
                 booktitle={VMV},
                 pages={227--234},
                 year={2010}
               }
          - <https://slideplayer.com/slide/14175246/> <https://slideplayer.com/slide/14175246/86/images/20/Bounding+Volume+Hierarchies+%28BVH%29.jpg>
   - **KD-Tree**
     - Muito eficiente, mas caro de construir
     - that maintains its high space utilization and excellent query and update performance regardless of the number of updates performed on it. The Bkd-tree is based on a well-known extensions of the kd-tree, called the K-D-B-tree, and on the so-called logarithmic method for making a static structure dynamic. As we show through extensive experimental studies, the Bkd-tree is able to achieve the almost 100% space utilization and the fast query processing of a static K-D-B-tree. However, unlike the K-D-B-tree, these properties are maintained over massive updates.
     - While static versions of the kd-tree have been shown to have excellent query performance in many practical situations, an efficient dynamic version has proven hard to develop. In the following, we give a brief overview of the internal memory kd-tree structure and then discuss the two most important previous approaches for obtaining external memory dynamic kd-trees.
     - In two dimensions, the kd-tree consists of a height log2 N  binary tree representing a recursive decomposition of the plane by means of axis-orthogonal lines partitioning the point set into two equal subsets.1 On even levels the line is orthogonal to the x-axis, while on odd levels it is orthogonal to the y-axis. The data points themselves are stored in the leaves.
     - <img width="720" height="540" alt="image" src="https://github.com/user-attachments/assets/06c23b55-3fd0-414d-a560-cbf91e3cc714" />

     - Fonte:
        - <https://users.cs.duke.edu/~pankaj/publications/papers/bkd-sstd.pdf>
           @inproceedings{procopiuc2003bkd,
                 title={Bkd-tree: A dynamic scalable kd-tree},
                 author={Procopiuc, Octavian and Agarwal, Pankaj K and Arge, Lars and Vitter, Jeffrey Scott},
                 booktitle={International symposium on spatial and temporal databases},
                 pages={46--65},
                 year={2003},
                 organization={Springer}
            }
        - <https://slidetodoc.com/today-kdtrees-bsp-trees-10112001-cs-638-fall/>

   - **Uniform Grid**
     - Simples
     - Ruim em cenas não uniformes
     - The technique, invented by the second author, is a flat, and thus non-hierarchical, grid whose resolution adapts to the data. It is especially suitable for telling efficiently which pairs of a large number of short edges intersect. Several of the algorithms presented here exist as working programs (among which is a visible surface program for polyhedra) and can handle large data sets (i.e. many thousands of geometric objects). Furthermore, the uniform grid is appropriate for parallel processing; the parallel implementation presented gives very good speed-up results.
     - which the authors believe may be quite fundamental in geometric computing in the sense understood above. (To word this claim a little more mildly, it must be stated that the grid is not a theoretical contribution on the lines of, for example, duality.) The uniform grid was invented by the second author more than a decade ago 2 and since then it has been successfully used to solve a rich collection of geometric problems. Among those problems, whose execution time the uniform grid vastly improves.
     - The uniform grid* is a regular grid overlaid on a scene. The 'fineness' of the grid is an experimentally determined function of the statistics of the given geometric objects. The uniform grid is especially suitable for telling efficiently which pairs of a large number of short edges intersect. This is the most time-consuming operation in programs aimed at resolving the issues cited in the preceding paragraph.
     - <img width="1024" height="768" alt="image" src="https://github.com/user-attachments/assets/28ac0e7c-d3a6-4973-b61a-babdb716bef0" />
     - Fonte:
        - <https://repository.bilkent.edu.tr/server/api/core/bitstreams/d1483aa4-bae8-47d3-8496-d26606d46bbf/content>
           @article{meagher1982geometric,
              title={Geometric modeling using octree encoding},
              author={Meagher, Donald},
              journal={Computer graphics and image processing},
              volume={19},
              number={2},
              pages={129--147},
              year={1982},
              publisher={Elsevier}
            }
        - <https://www.slideserve.com/manju/ray-casting>
   - **Octree**
     - Divisão recursiva do espaço
     - A geometric modeling technique called Octree Encoding is presented. Arbitrary 3-D objects can be represented to any specified resolution in a hierarchical 8-ary tree structure or “octree” Objects may be concave or convex, have holes (including interior holes), consist of disjoint parts, and possess sculptured (i.e., “free-form”) surfaces. The memory required for representation and manipulation is on the order of the surface area of the object. A complexity metric is proposed based on the number of nodes in an object's tree representation. Efficient (linear time) algorithms have been developed for the Boolean operations (union, intersection and difference), geometric operations (translation, scaling and rotation), N-dimensional interference detection, and display from any point in space with hidden surfaces removed. 
     - <img width="921" height="844" alt="image" src="https://github.com/user-attachments/assets/60dfa5bd-47c5-4689-abc6-b9186a501420" />
     - Fonte:
        - <https://fab.cba.mit.edu/classes/S62.12/docs/Meagher_octree.pdf>
           @article{meagher1982geometric,
              title={Geometric modeling using octree encoding},
              author={Meagher, Donald},
              journal={Computer graphics and image processing},
              volume={19},
              number={2},
              pages={129--147},
              year={1982},
              publisher={Elsevier}
            }

2. **Intermediárias**

   - **BSP Tree (Binary Space Partitioning)**
     - Generalização do KD-tree
     - A Binary Space Partitioning (BSP) tree is simple and powerful data structure that can b e used to solve a variety of geometrical problems. In case of the ray tracing a BSP tree is often constructed using splitting planes perpendicular to principal axes only. It is advantageous especially when rendered objects with complex shapes are enclosed by axis{aligned bounding boxes. Moreover, the orthogonality of BSP tree decreases the numb er of computations required for an intersection of a ray and a splitting plane.
     - When nding the nearest object pierced by a ray during rendering process, a BSP tree is traversed from the root to the leaves. Corrected sequence of leaves has to be identied for a given ray origin and direction. The nearest leaf has to be processed first. The splitting plane subdivides a rectangular cell into two smaller ones. The test performed during the traversal has to determine, whether to visit both nodes and in which order or just one node and which one.
     - <img width="802" height="754" alt="image" src="https://github.com/user-attachments/assets/39781def-a232-493f-b1c2-0db22cce43d4" />
     - a BSP is a binary tree that partitions space into two half-spaces according to a splitting plane. This property allows BSPs to be used as a binary search tree to locate objects embedded in that space. If a splitting plane intersects an object, the object must be put on both sides of the plane. This property can in theory lead to poor quality BSP trees with Ω(n2) nodes for certain configurations of n non-intersecting triangles in ℜ3 [13]. However, in practice this will not occur and space should be closer to linear. In fact, if we only have fat triangles — which means there are no long and skinny triangles — then there exist BSP trees with linear size [3]. Assuming the tree is well balanced, query time is usually O(log n). Build time depends on the algorithm used to pick the splitting planes. An algorithm that chose the optimal splitting planes would likely take at least exponential time which is not feasible. For this reason, splitting planes are usually chosen at random, to divide space or the elements in half, or using some other heuristic such as the greedy
     - Fonte:
        - <https://www.researchgate.net/profile/Vlastimil-Havran/publication/266448413_Fast_robust_BSP_tree_traversal_algorithm_for_ray_tracing/links/58ef3dcda6fdcc61cc128e92/Fast-robust-BSP-tree-traversal-algorithm-for-ray-tracing.pdf>
           @article{havran1997fast,
              title={Fast robust BSP tree traversal algorithm for ray tracing},
              author={Havran, Vlastimil and Kopal, Tomas and Bittner, Ji{\v{r}}{\'\i} and {\v{Z}}{\'a}ra, Ji{\v{r}}{\'\i}},
              journal={Journal of graphics tools},
              volume={2},
              number={4},
              pages={15--23},
              year={1997},
              publisher={Taylor \& Francis}
            }
        - <https://www.researchgate.net/profile/Ingo-Wald/publication/4375571_Ray_tracing_with_the_BSP_tree/links/00463524acc7c34e8f000000/Ray-tracing-with-the-BSP-tree.pdf>
           @inproceedings{ize2008ray,
              title={Ray tracing with the BSP tree},
              author={Ize, Thiago and Wald, Ingo and Parker, Steven G},
              booktitle={2008 IEEE Symposium on Interactive Ray Tracing},
              pages={159--166},
              year={2008},
              organization={IEEE}
            }

   - **Bounding Interval Hierarchy (BIH)**
     - Mais simples que BVH
     - The Bounding Interval Hierarchy is a simple algorithm, which at the same time offers exceptional speed for both static and dynamic scenes, features much higher numerical precision, and allows one to
a priori fix the memory footprint. It can be considered as the cross-over of the advantages of partitioning object lists and efficiently traversing spatial partitions
     - Comparisons with two fully optimized state-of-the-art kd-tree based ray tracers (InView and our own implementation) show that it can outperform them for most scenes by a factor of two to even some orders of magnitudes for both total rendering time and overall memory consumption
     - Unlike classic bounding volume hierarchies [KK86,GM03], which store a full axis aligned bounding box for each child, the idea of the bounding interval hierarchy is to only store two parallel planes perpendicular to either one of x, y, and z-axis.
     - Given a bounding box and the axis, the left child L results from replacing the maximum value along that axis by the first plane. In an analogue way the right child R results from replacing the minimum value by the second plane (see figure 2). Resulting zero volumes are used to represent empty children.
     - <img width="726" height="749" alt="image" src="https://github.com/user-attachments/assets/a7c6af0b-eb18-4df1-ba35-37fb9ed3d0d5" />
     - The inner nodes of the tree are described by the two clipping planes and a pointer to a pair of children. As this sums up to 12 bytes in total, all nodes are aligned on four-byte-boundaries. This allows one to use the lower two bits of the children-pointer to indicate the axis (00: x, 01: y, 10: z) or a leaf (case 11). Leaf nodes consist of a 32bit-pointer to the referenced objects and their overall number. The overhead of four bytes in the leafs (as they only use eight bytes out of the node data structure) can be resolved by a careful implementation.
     - <img width="715" height="339" alt="image" src="https://github.com/user-attachments/assets/ccf26c8d-c6b7-426c-abb6-f42c962f24c9" />
     - Fonte:
        - <https://diglib.eg.org/server/api/core/bitstreams/c4d20a14-839e-4335-ab16-549542dc6398/content>
           @article{wachter2006instant,
              title={Instant ray tracing: The bounding interval hierarchy.},
              author={W{\"a}chter, Carsten and Keller, Alexander},
              journal={Rendering Techniques},
              volume={2006},
              number={139-149},
              pages={130},
              year={2006}
            }

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
