package ar.jmenes.correlativasjmenes.repositories;

import ar.jmenes.correlativasjmenes.model.Materia;
import org.springframework.stereotype.Repository;

import java.util.ArrayList;
import java.util.List;

@Repository
public class MateriaRepository {

    private List<Materia> materias;
    private static Long sequence = 0L;

    private static Long nextId(){
        sequence+=1;
        return sequence;
    }

    public MateriaRepository(){
        super();
        this.materias = new ArrayList<Materia>();
    }

    public List<Materia> findAll(){
        return this.materias;
    }

    public Materia findById(Long id){
        for (Materia materia : materias){
            if (materia.getId().equals(id))
                return materia;
        }
        return null;
    }

    public Materia save (Materia materia){
        materia.setId(nextId());
        this.materias.add(materia);
        return materia;
    }

    public void delete (String codigo, String nombre){
        this.materias.removeIf(unaMateria -> unaMateria.getCodigo().equals(codigo) && unaMateria.getNombre().equals(nombre) );
        for (Materia unaMateria : materias){
            unaMateria.deleteCorrelativa(codigo, nombre);
        }
    }

    public void update(Long idMateria, String unNombre, String unCodigo){
        for (Materia unaMateria : materias){
            if (unaMateria.getId().equals(idMateria)){
                unaMateria.setNombre(unNombre);
                unaMateria.setCodigo(unCodigo);
                //unaMateria.setMateriasRequeridas(unasCorrelativas);
            }
        }
    }


}
