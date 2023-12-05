package ar.jmenes.correlativasjmenes.controllers;

import ar.jmenes.correlativasjmenes.model.Materia;
import ar.jmenes.correlativasjmenes.repositories.MateriaRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;

@Controller
public class MateriaController {

    @Autowired
    private MateriaRepository repositorioMaterias;

    @GetMapping("/materia/{idMateria}")
    public String mostrarMateria(Model model, @PathVariable("idMateria") Long idMateria){
        Materia materia = repositorioMaterias.findById(idMateria);
        model.addAttribute("materiaHtml",materia);
        return "materia";
    }

    @GetMapping("/materias")
    public String listarMaterias(Model model){
        model.addAttribute("materiasHtml",repositorioMaterias.findAll());
        return "materias";
    }

    @PostMapping("/materia")
    public String addMateria(Model model, String nombre, String codigo){
        repositorioMaterias.save(new Materia(nombre,codigo));
        model.addAttribute("materiasHtml",repositorioMaterias.findAll());
        return "materias";
    }

    @PostMapping ("/materia/delete")
    public String deleteMateria (Model model,@RequestParam String nombre, @RequestParam String codigo){
        repositorioMaterias.delete(codigo,nombre);
        return "redirect:/materias";
    }

    @GetMapping ("/materia/{idMateria}/update")
    public String updateMateria (Model model, @PathVariable("idMateria") Long idMateria, @RequestParam String nombre, @RequestParam String codigo){
        Materia materia = repositorioMaterias.findById(idMateria);
        model.addAttribute("materiaHtml",materia);
        repositorioMaterias.update(idMateria, nombre, codigo);
        return "redirect:/materia/"+idMateria;
    }

}
