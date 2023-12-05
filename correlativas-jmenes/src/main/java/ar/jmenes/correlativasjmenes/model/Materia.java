package ar.jmenes.correlativasjmenes.model;

import java.util.ArrayList;
import java.util.Collection;

public class Materia {
    private Long id;
    private String nombre;
    private String codigo;
    private Collection<Materia> materiasRequeridas;

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Materia(String nombre, String codigo) {
        this.nombre = nombre;
        this.codigo = codigo;
        this.materiasRequeridas = new ArrayList<Materia>();
    }
    public Materia(){
        super();
        this.materiasRequeridas = new ArrayList<Materia>();
    }
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public Collection<Materia> getMateriasRequeridas() {
        return materiasRequeridas;
    }

    public void setMateriasRequeridas(Collection<Materia> materiasRequeridas) {
        this.materiasRequeridas = materiasRequeridas;
    }

    public void addCorrelativa (Materia unaMateria){
        this.materiasRequeridas.add(unaMateria);
    }

    public void deleteCorrelativa (String codigo,String nombre){
        this.materiasRequeridas.removeIf(unaMateria -> unaMateria.getCodigo().equals(codigo) && unaMateria.getNombre().equals(nombre) );
    }
}
